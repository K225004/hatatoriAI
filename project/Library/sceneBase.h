#pragma once
#include <list>
#include "sceneManager.h"
class GameObject;

template <class C>
C* Instantiate() {
	C* obj = new C();
	SceneManager::CurrentScene()->Push((GameObject*)obj);
	return obj;
};

template <class C>
C* FindGameObject() {
	auto objects = SceneManager::CurrentScene()->GetAllNodes();
	for (auto& m : objects) {
		C* obj = dynamic_cast<C*>(m.object);
		if (obj != nullptr)
			return obj;
	}
	return nullptr;
}

template <class C>
std::list<C*> FindGameObjects() {
	auto objects = SceneManager::CurrentScene()->GetAllNodes();
	std::list<C*> list;
	for (const auto& m : objects) {
		C* obj = dynamic_cast<C*>(m.object);
		if (obj != nullptr)
			list.emplace_back(obj);
	}
	return list;
}

template<class C>
C* FindGameObjectWithTag(std::string _tag) {
	auto objects = SceneManager::CurrentScene()->GetAllNodes();
	for (const auto& m : objects) {
		C* obj = dynamic_cast<C*>(m.object);
		if (obj != nullptr && obj->GetTag() == _tag)
			return obj;
	}
	return nullptr;
}

template<class C>
C* FindGameObjectsWithTag(std::string _tag) {
	auto objects = SceneManager::CurrentScene()->GetAllNodes();
	std::list<C*> list;
	for (const auto& m : objects) {
		C* obj = dynamic_cast<C*>(m.object);
		if (obj != nullptr && obj->GetTag() == _tag)
			list.push_back(obj);
	}
	return list;
}

class SceneBase {
public:
	SceneBase();
	SceneBase(bool flag);
	virtual ~SceneBase();

	virtual void Update();
	virtual void Draw();

	/// <summary>
	/// GameObjectを生成する
	/// ここで生成すると、Update,Drawが呼ばれるようになる
	/// </summary>
	template <class C>
	C* CreateGameObject() {
		C* obj = new C(this);
		Push(obj);
		return obj;
	};

	/// <summary>
	/// GameObjectを生成する
	/// ここで生成すると、Update,Drawが呼ばれるようになる
	/// </summary>
	template <class C>
	C* Instantiate() {
		C* obj = new C();
		Push(obj);
		return obj;
	};

	/// <summary>
	/// クラスが一致したGameObjectを取得する
	/// </summary>
	/// <returns>GameObjectのインスタンス</returns>
	template<class C>
	C* FindGameObject() const {
		for (const auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr)
				return obj;
		}
		return nullptr;
	}

	/// <summary>
	/// クラスが一致したGameObjectを全て取得する
	/// </summary>
	/// <returns>GameObjectのインスタンス</returns>
	template<class C>
	std::list<C*> FindGameObjects() const {
		std::list<C*> list;
		for (const auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr)
				list.emplace_back(obj);
		}
		return list;
	}

	template<class C>
	C* FindGameObjectWithTag(std::string _tag) const {
		for (const auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr && obj->GetTag() == _tag)
				return obj;
		}
		return nullptr;
	}

	template<class C>
	C* FindGameObjectsWithTag(std::string _tag) const {
		std::list<C*> list;
		for (const auto& m : m_objects) {
			C* obj = dynamic_cast<C*>(m.object);
			if (obj != nullptr && obj->GetTag() == _tag)
				list.push_back(obj);
		}
		return list;
	}

	inline void Push(GameObject* obj)
	{
		NODE node;
		node.object = obj;
		m_objects.emplace_back(node);
		m_needSort = true;
	}

	/// <summary>
	/// 描画のプライオリティを設定する
	/// 数値が少ない順に描画されるので、２Ｄでは奥に表示される
	/// ２Ｄで手前に表示したい時、３Ｄで後に描画したい時は、値を高くする
	/// プライオリティが同じものの順番は保証されない
	/// プライオリティのデフォルトは100です
	/// </summary>
	/// <param name="obj">プライオリティを設定するオブジェクト</param>
	/// <param name="order">描画プライオリティ</param>
	void SetDrawOrder(GameObject* _obj, int _order);

	/// <summary>
	/// GameObjectを削除する
	/// </summary>
	/// <param name="obj">GameObjectのインスタンス</param>
	void DeleteGameObject(GameObject* obj);

	/// <summary>
	/// 全てのGameObjectを削除する
	/// </summary>
	void DeleteAllGameObject();

	/// <summary>
	/// すべてのGameObjectを取得する
	/// </summary>
	/// <returns>すべてのGameObjectのリスト</returns>
	std::list<GameObject*> GetAllObjects() const;

	struct NODE {
		int order;
		bool initialized;
		GameObject* object;
		NODE() : order(100), object(nullptr), initialized(false) {}
	};

	/// <summary>
	/// すべてのGameObjectNodeを取得する
	/// </summary>
	/// <returns>すべてのGameObjectのリスト</returns>
	const std::list<NODE>& GetAllNodes() const { return m_objects; }
private:
	std::list<NODE> m_objects;     // ここで管理しているGameObjectリスト
	std::list<NODE> m_drawObjects; // 描画用のGameObjectリスト
	bool m_needSort;

	void DeleteFromDrawObjects(GameObject* obj);
	static bool Comp(const NODE& o1, const NODE& o2);
};
