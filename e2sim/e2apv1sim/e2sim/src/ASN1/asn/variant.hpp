#pragma once

/******************************************************************************
*
*   Copyright (c) 2019 AT&T Intellectual Property.
*   Copyright (c) 2018-2019 Nokia.
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
******************************************************************************/

// Standard Includes: ANSI C/C++, MSA, and Third-Party Libraries
#include <typeinfo>
#include <cassert>


// Local Includes: Application specific classes, functions, and libraries


namespace asn{

template<size_t S>
struct variant
{
	typedef variant<S> self_type;
	
	template <typename T>
	static void check_size () {static_assert(sizeof (T) <= S, "wrong type");}	
	
	variant ()
	: typeinfo (nullptr)
	{}
	
	template <typename T>
	variant (const T& t)
	: typeinfo (&typeid (T))
	{
		check_size<T>();
		new (as_<T>()) T (t);
	}

	~variant ()
	{
		assert(!typeinfo);
	}

	template <typename T>
	T& build ()
	{
		assert(!typeinfo);
		typeinfo = & typeid (T);
		return *new (as_<T>()) T;
	}
    
	template <typename T>
	T& build (const T& t)
	{
		assert(!typeinfo);
		check_size<T>();
		typeinfo = & typeid (T);
		return *new (as_<T> ()) T (t);
	}

	template <typename T>
	T& as()
	{
		assert(*typeinfo == typeid (T));
		check_size<T>();
		return *as_<T> ();
	}
	
	template <typename T>
	const T& as() const
	{
		assert(*typeinfo == typeid (T));
		check_size<T>();
		return *as_<T> ();
	}

    template <typename T>
    void swap(self_type& other)
    {
    	assert (typeinfo);
    	assert (*typeinfo == *other.typeinfo);
		std::swap (as<T> (), other.as<T> ());
    }

    template <typename T>
    void move(self_type& other)
    {
		build<T> ();
		swap<T> (other);
		other.destroy<T> ();
    }

	template <typename T>
	void copy(const self_type& other)
	{
		build<T> (other.as<T> ());
	}
	
	template <typename T>
	void destroy()
	{
		as<T> ().~T ();
		typeinfo = nullptr;
	}

private:
	self_type& operator=(const self_type&){}
	variant (const self_type&){}
	
	template <typename T>
	T* as_()
	{
		void *p = buffer.raw;
		return static_cast<T*> (p);
	}
	
	template <typename T>
	const T* as_() const
	{
		const void *p = buffer.raw;
		return static_cast<const T*> (p);
	}
  
	union
	{
		long double align_me;
		char raw[S];
	} buffer;
	
	const std::type_info *typeinfo;
};

} //namspace asn
