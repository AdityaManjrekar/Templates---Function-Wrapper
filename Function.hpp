#include<iostream>
#include <cstddef>

namespace cs540
{
	class Reference
	{
	public:
		Reference(){
			}
			virtual ~Reference() {
			}
	};
	
	// hold the actual data of type T.
	template <typename T>
	class ReferenceObject : public Reference{
		public:
			T data;
			ReferenceObject(T temp) : data(temp) {}
			~ReferenceObject() { }
	};

	
	template <typename> class Function;
	
	template <typename ResultType, typename ... ArgumentTypes> 
	class Function<ResultType(ArgumentTypes...)>
	{
		public:
		Reference *data;

		Function() : data(NULL) {}
		template <typename FunctionType> 
		Function(FunctionType func) : data(new ReferenceObject<FunctionType>(func))
		{
			 
		}
		
	};
	
}