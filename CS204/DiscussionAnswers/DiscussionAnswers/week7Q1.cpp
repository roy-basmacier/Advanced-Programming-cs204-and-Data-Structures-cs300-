template <class itemType>

itemType ::operator [] (int i)

{
	int count = 0;
	itemType * nptr;
	for (nptr = head; count < i && nptr; nptr->next)
	{
		count++;
	}

	return nptr;
}