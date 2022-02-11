#pragma once
template<typename TKey, typename TValue>
struct Item
{
	TKey itemKey;
	TValue itemValue;
};

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>();
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>();

	/// <summary>
	/// Delets all items in dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks to see if an item that has the given key is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool containsKey(const TKey object)const;

	/// <summary>
	/// Checks to see if an item that has the given value is in the dictionary
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool containsTValue(const TValue object)const;


	/// <summary>
	/// Creates a new item with the given key and value and adds it to the dictionary
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	void addItem(const TKey& key, const TValue& value)const;

	/// <summary>
	/// Tries to find the item that matches the given key
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	bool tryGetValue(const TKey key, const TValue& value)const;

	/// <summary>
	/// removes the item that has the given key
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
	bool remove(const TKey key);

	/// <summary>
	/// Removes the item that has the given key and gives back rthe value of the item that was removed
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Gets the number of items in the dictionary
	/// </summary>
	/// <returns></returns>
	int getCount()const;

	const Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue> other);


private:

	Item<TKey, TValue>* m_items = nullptr;

	int m_count = 0;
};