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

	/// <summary>
	/// Sets the values from an old dictionary to be equal to the new dictionary.
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	const Dictionary<TKey, TValue>& operator=(const Dictionary<TKey, TValue> other);

	/// <summary>
	/// Checks if the item has a key if so then give the value.
	/// </summary>
	/// <param name="key"></param>
	/// <returns></returns>
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
	clear();
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	//iterates though the items
	for (int i = 0; i < getCount(); i++)
	{
		//removes the items key and value
		remove(m_items[i].itemKey, m_items[i].itemValue);
	}
	//resets the count
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
	// If there are no items in the list...
	if (containsKey(key))
		return;

	//create a temp array
	Item* temp = new Item[getCount() + 1];

	//iterates through the items
	for (int i = 0; i < getCount(); i++)
	{
		//if the item key is equal to the key
		if (m_items[i].itemKey == key)
			return;
		//makes the temp array equal to the items
		temp[i] = m_items[i];
	}

	//sets the item key to the key
	temp[getCount()].itemKey = key;
	//sets the item value to the value
	temp[getCount()].itemValue = value;

	m_items = temp;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	// If there are no item keys in the list...
	if (!containsKey(key))
		// ...return false.
		return false;

	//creates a temp array
	Item* temp = new Item[getCount() - 1];
	bool itemIsRemoved = false;

	//iterates through the items
	for (int i = 0; i < getCount(); i++)
	{
		//if the item key is not a key
		if (m_items[i].itemKey != key)
		{
			//makes the temp array equal to the items
			temp[i] = m_items[i];
		}
		else
			itemIsRemoved = true;	
	}
	delete m_items;
	//set the items to be the temp items
	m_items = temp;
	m_count--;

	return itemIsRemoved;
}                  

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	// If there are no items in the list...
	if (!containsKey(key))
		// ...return false.
		return false;

	//creates a temp array of items 
	Item* temp = new Item[getCount() - 1];
	bool itemIsRemoved = false;

	//iterates through the items
	for (int i = 0; i < getCount(); i++)
	{
		//if the item key is not a key
		if (m_items[i].itemKey != key)
		{
			//makes the temp array equal to the items
			temp[i] = m_items[i];
		}
		else
		{
			//sets value to be the items key if the item is removed
			value = m_items[i].itemValue;
			itemIsRemoved = true;
		}
	}

	//set the items to be the temp items
	m_items = temp;
	m_count--;

	return itemIsRemoved;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	//iterates through the items
	for (int i = 0; i < other.getCount(); i++)
		//adds items based on the others items 
		addItem(other.m_items[i].itemKey, other.m_items[i].itemValue);

	//sets the count to be the other count
	m_count = other.getCount();

	return other;
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey key)
{
	TValue value;
	// If the key can be found
	if (tryGetValue(key, value))
		// return the value found
		return value;
	// If there is no key found
	else
		//return an empty value
	return TValue();
}
