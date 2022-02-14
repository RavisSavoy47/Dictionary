#pragma once

template<typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>() {};
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
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Tries to find the item that matches the given key
	/// </summary>
	/// <param name="key"></param>
	/// <param name="value"></param>
	/// <returns></returns>
	bool tryGetValue(const TKey key, TValue& value)const;

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

	TValue operator[](const TKey key);

private:

	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;

	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	m_items = other.m_items;
	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::~Dictionary()
{
	
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	for (int i = 0; i < getCount(); i++)
	{

	}

	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//iterates through the items 
	for (int i = 0; i < getCount(); i++)
	{
		//checks if the item is a key
		if (m_items[i].itemKey == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsTValue(const TValue object) const
{
	//iterates through the items 
	for (int i = 0; i < getCount(); i++)
	{
		//checks if the item is a value
		if (m_items[i].itemValue == object)
			return true;
	}

	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	//iterates through the items 
	for (int i = 0; i < getCount(); i++)
	{
		//checks if the item is a key
		if (m_items[i].itemKey == key)
		{
			//set the value to be the items value
			value = m_items[i].itemValue;
			return true;
		}
	}

	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	Item* temp = new Item[getCount() + 1];

	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey == key)
			return;

		temp[i] = m_items[i];
	}

	temp[getCount()].itemKey = key;
	temp[getCount()].itemValue = value;

	m_items = temp;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	Item* temp = new Item[getCount() - 1];
	int j = 0;
	bool itemIsRemoved = false;

	for (int i = 0; i < getCount(); i++)
	{
		if (m_items[i].itemKey != key)
		{
			temp[j] = m_items[i];
			j++;
		}
		else
			itemIsRemoved = true;	
	}

	m_items = temp;
	m_count--;

	return itemIsRemoved;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	return false;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	// TODO: insert return statement here
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	return TValue();
}
