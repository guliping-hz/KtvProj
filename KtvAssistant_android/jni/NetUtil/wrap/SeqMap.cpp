﻿#include "seqmap.h"

namespace NetworkUtil
{
//	template <class T,class Map>
//	SeqMap_ThreadSafe<T,Map>::SeqMap_ThreadSafe()
//		:m_pCSW(NULL)
//	{
//		m_pCSW = CriticalSectionWrapper::CreateCriticalSection(); 
//		assert(m_pCSW!=NULL);
//	}

//	template <class T,class Map>
//	void SeqMap_ThreadSafe<T,Map>::Put(int id,T t)
//	{
//		//加入临界区的保护，使之具有线程安全。
//		CriticalSectionScoped g(m_pCSW);
//		SeqMap<T,Map>::Put(id,t);
//	}
//	template <class T,class Map>
//	void SeqMap_ThreadSafe<T,Map>::Cover(int id,T t)
//	{
//		CriticalSectionScoped g(m_pCSW);
//		SeqMap<T,Map>::Cover(id,t);
//	}
//	template <class T,class Map>
//	T* SeqMap_ThreadSafe<T,Map>::Get(int id)
//	{
//		CriticalSectionScoped g(m_pCSW);
//		return SeqMap<T,Map>::Get(id);
//	}

//	template <class T,class Map>
//	inline void SeqMap_ThreadSafe<T,Map>::Del(int id)
//	{
//		CriticalSectionScoped g(m_pCSW);
//		SeqMap<T,Map>::Del(id);
//	}
//	template <class T,class Map>
//	inline unsigned int SeqMap_ThreadSafe<T,Map>::Size()
//	{
//		CriticalSectionScoped g(m_pCSW);
//		return SeqMap<T,Map>::Size();
//	}
//	template <class T,class Map>
//	inline void SeqMap_ThreadSafe<T,Map>::Clear()
//	{
//		CriticalSectionScoped g(m_pCSW);
//		SeqMap<T,Map>::Clear();
//	}
}
