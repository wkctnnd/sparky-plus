#pragma once
namespace spakry
{
#define DECLARE_DELEGATE(TypeName) \
	template<typename ReturnType> \
	class TypeName \
	{ \
	public: \
		TypeName() \
		{\
			m_p = NULL;\
			m_F = NULL;\
		}\
		~TypeName()\
		{ \
		} \
	protected:\
		typedef ReturnType(* F)(void * p);\
		void * m_p;\
		F m_F;\
		template<class T,ReturnType (T::*FunName)()>\
		static ReturnType MethodStub(void * p)\
		{\
			T * Ap = (T *)p;\
			return (Ap->*FunName)();\
		}\
		template<ReturnType(*FunName)()>\
		static ReturnType FunStub(void * p)\
		{\
			return (FunName)();\
		}\
		static TypeName Create(void * p , F f)\
		{\
			TypeName Temp;\
			Temp.m_F = f;\
			Temp.m_p = p;\
			return Temp;\
		}\
		public:\
		template<class T,ReturnType (T::*FunName)()>\
		static TypeName FromMethod( T * p)\
		{\
			return Create((void*)p, &MethodStub<T,FunName>);\
		}\
		template<ReturnType(*FunName)()>\
		static TypeName FromFun()\
		{\
			return Create(NULL, &FunStub<FunName>);\
		}\
		ReturnType Excute()\
		{\
			return (*m_F)(m_p);\
		}\
}; 


#define DECLARE_DELEGATE_ONE(TypeName) \
	template<typename ReturnType,typename A1> \
	class TypeName \
	{ \
	public: \
		TypeName() \
		{\
			m_p = NULL;\
			m_F = NULL;\
		}\
		~TypeName()\
		{ \
		} \
	protected:\
		typedef ReturnType(* F)(void * p,A1);\
		void * m_p;\
		F m_F;\
		template<class T,ReturnType (T::*FunName)(A1)>\
		static ReturnType MethodStub(void * p,A1 a1)\
		{\
		T * Ap = (T *)p;\
			return (Ap->*FunName)(a1);\
		}\
		template<ReturnType(*FunName)(A1)>\
		static ReturnType FunStub(void * p,A1 a1)\
		{\
			return (FunName)(a1);\
		}\
		static TypeName Create(void * p , F f)\
		{\
			TypeName Temp;\
			Temp.m_F = f;\
			Temp.m_p = p;\
			return Temp;\
		}\
		public:\
		template<class T,ReturnType (T::*FunName)(A1)>\
		static TypeName FromMethod( T * p)\
		{\
			return Create((void*)p, &MethodStub<T,FunName>);\
		}\
		template<ReturnType(*FunName)(A1)>\
		static TypeName FromFun()\
		{\
			return Create(NULL, &FunStub<FunName>);\
		}\
		ReturnType Excute(A1 a1)\
		{\
			return (*m_F)(m_p,a1);\
		}\
}; 


#define DECLARE_DELEGATE_TWO(TypeName) \
	template<typename ReturnType,typename A1,typename A2> \
	class TypeName \
	{ \
	public: \
		TypeName() \
		{\
			m_p = NULL;\
			m_F = NULL;\
		}\
		~TypeName()\
		{ \
		} \
	protected:\
		typedef ReturnType(* F)(void * p,A1,A2);\
		void * m_p;\
		F m_F;\
		template<class T,ReturnType (T::*FunName)(A1,A2)>\
		static ReturnType MethodStub(void * p,A1 a1,A2 a2)\
		{\
			T * Ap = (T *)p;\
			return (Ap->*FunName)(a1,a2);\
		}\
		template<ReturnType(*FunName)(A1,A2)>\
		static ReturnType FunStub(void * p,A1 a1,A2 a2)\
		{\
			return (FunName)(a1,a2);\
		}\
		static TypeName Create(void * p , F f)\
		{\
			TypeName Temp;\
			Temp.m_F = f;\
			Temp.m_p = p;\
			return Temp;\
		}\
		public:\
		template<class T,ReturnType (T::*FunName)(A1,A2)>\
		static TypeName FromMethod( T * p)\
		{\
			return Create((void*)p, &MethodStub<T,FunName>);\
		}\
		template<ReturnType(*FunName)(A1,A2)>\
		static TypeName FromFun()\
		{\
			return Create(NULL, &FunStub<FunName>);\
		}\
		ReturnType Excute(A1 a1,A2 a2)\
		{\
			return (*m_F)(m_p,a1,a2);\
		}\
}; 


#define DECLARE_DELEGATE_THREE(TypeName) \
	template<typename ReturnType,typename A1,typename A2,typename A3> \
	class TypeName \
	{ \
	public: \
		TypeName() \
		{\
			m_p = NULL;\
			m_F = NULL;\
		}\
		~TypeName()\
		{ \
		} \
	protected:\
		typedef ReturnType(* F)(void * p,A1,A2,A3);\
		void * m_p;\
		F m_F;\
		template<class T,ReturnType (T::*FunName)(A1,A2,A3)>\
		static ReturnType MethodStub(void * p,A1 a1,A2 a2,A3 a3)\
		{\
			T * Ap = (T *)p;\
			return (Ap->*FunName)(a1,a2,a3);\
		}\
		template<ReturnType(*FunName)(A1,A2,A3)>\
		static ReturnType FunStub(void * p,A1 a1,A2 a2,A3 a3)\
		{\
			return (FunName)(a1,a2,a3);\
		}\
		static TypeName Create(void * p , F f)\
		{\
			TypeName Temp;\
			Temp.m_F = f;\
			Temp.m_p = p;\
			return Temp;\
		}\
		public:\
		template<class T,ReturnType (T::*FunName)(A1,A2,A3)>\
		static TypeName FromMethod( T * p)\
		{\
			return Create((void*)p, &MethodStub<T,FunName>);\
		}\
		template<ReturnType(*FunName)(A1,A2,A3)>\
		static TypeName FromFun()\
		{\
			return Create(NULL, &FunStub<FunName>);\
		}\
		ReturnType Excute(A1 a1,A2 a2,A3 a3)\
		{\
			return (*m_F)(m_p,a1,a2,a3);\
		}\
	};




	//template<typename R, typename A1, typename A2, class C>
	//class Delegate
	//{
	//public:
	//	Delegate()
	//	{
	//		
	//	}


	//private:
 //
	//	typedef R(*FNew)(void*p, A1, A2);

	//	void* m_p;
	//	FNew m_f;

	//public:
	//	template<class C, R(C::*CF)(A1, A2)>
	//	static int MethodStub(void* p, A1 a1, A2 a2)
	//	{
	//		C *Ap = (C*)p;
	//		return (Ap->*cf);
	//	}


	//	template<R(*F)(A1,A2)>
	//	static int FunStub(void *p, A1 a1, A2 a2)
	//	{
	//		return (p)(a1, a2);
	//	}


	//	static Delegate Create(void* p, FNew f)
	//	{
	//		Delegate Temp;
	//		Temp.m_F = f;
	//		Temp.m_p = p;
	//		return Temp;
	//	}

	//	template<class C, R(C::*CF)(A1, A2)>
	//	static Delegate FromMethod(C *p)
	//	{
	//		return Create(p, &MethodStub<C, CF>);
	//	}


	//	template<R(*F)(A1, A2)>
	//	static Delegate FromFun()
	//	{
	//		return Create(NULL, &FunStub<F>);
	//	}

	//	int Execute(int a1, int a2)
	//	{
	//		return (*m_F)(m_p, a1, a2);
	//	}

	//};

}