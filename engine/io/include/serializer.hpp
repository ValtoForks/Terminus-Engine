#pragma once

#include <stdint.h>
#include <string>
#include <io/include/reflection.hpp>

#include <stack>

TE_BEGIN_TERMINUS_NAMESPACE

class ISerializer
{
public:
	ISerializer() {}
	virtual ~ISerializer() {}
	virtual void serialize(const char* name, bool& value)					 = 0;
	virtual void serialize(const char* name, int8_t& value)					 = 0;
	virtual void serialize(const char* name, uint8_t& value)				 = 0;
	virtual void serialize(const char* name, int16_t& value)				 = 0;
	virtual void serialize(const char* name, uint16_t& value)				 = 0;
	virtual void serialize(const char* name, int32_t& value)				 = 0;
	virtual void serialize(const char* name, uint32_t& value)				 = 0;
	virtual void serialize(const char* name, float& value)					 = 0;
	virtual void serialize(const char* name, double& value)					 = 0;
	virtual void serialize(const char* name, std::string& value)			 = 0;
	virtual void serialize(const char* name, const char* value)				 = 0;

	virtual void begin_serialize_struct(const char* name)					 = 0;
	virtual void end_serialize_struct(const char* name)					 = 0;
	virtual void begin_serialize_array(const char* name, int count)  = 0;
	virtual void end_serialize_array(const char* name)				 = 0;
	
	virtual void deserialize(const char* name, bool& value) = 0;
	virtual void deserialize(const char* name, int8_t& value) = 0;
	virtual void deserialize(const char* name, uint8_t& value) = 0;
	virtual void deserialize(const char* name, int16_t& value) = 0;
	virtual void deserialize(const char* name, uint16_t& value) = 0;
	virtual void deserialize(const char* name, int32_t& value) = 0;
	virtual void deserialize(const char* name, uint32_t& value) = 0;
	virtual void deserialize(const char* name, float& value) = 0;
	virtual void deserialize(const char* name, double& value) = 0;
	virtual void deserialize(const char* name, std::string& value, bool is_static = true) = 0;
	virtual void deserialize(const char* name, char** value, bool is_static = true) = 0;

	virtual void begin_deserialize_struct(const char* name) = 0;
	virtual void end_deserialize_struct(const char* name) = 0;
	virtual int  begin_deserialize_array(const char* name) = 0;
	virtual void end_deserialize_array(const char* name) = 0;

	virtual void print() = 0;
	virtual bool is_raw_serializable() = 0;

	virtual void raw_serialize(void* data, const size_t& size) = 0;
	virtual void raw_deserialize(void* data, const size_t& size) = 0;

	inline void push_array_index(int idx) { m_index_stack.push(idx); }
	inline void pop_array_index() { m_index_stack.pop(); }

	template <typename T>
	void serialize_complex(const char* name, T& value, bool raw)
	{
		if (raw && is_raw_serializable())
			raw_serialize(&value, sizeof(T));
		else
		{
			begin_serialize_complex(name);
			value.serialize(this);
			end_serialize_complex(name);
		}
	}

	template <typename T>
	void serialize_complex_array(const char* name, T* value, int count, bool raw)
	{
		if (raw && is_raw_serializable())
			raw_serialize(value, sizeof(T) * count);
		else
		{
			begin_serialize_complex_array(name, count);

			for (int i = 0; i < count; i++)
			{
				begin_serialize_complex(name);
				value[i].serialize(this);
				end_serialize_complex(name);
			}

			end_serialize_complex_array(name);
		}
	}

	template <typename T>
	void deserialize_complex(const char* name, T& value, bool raw)
	{
		if (raw && is_raw_serializable())
			raw_deserialize(&value, sizeof(T));
		else
		{
			begin_deserialize_complex(name);
			value.deserialize(this);
			end_deserialize_complex(name);
		}
	}

	template <typename T>
	void deserialize_complex_array(const char* name, T* value, bool raw)
	{
		int size = begin_deserialize_complex_array(name);

		if (raw && is_raw_serializable())
			raw_deserialize(value, sizeof(T) * size);
		else
		{
			for (int i = 0; i < size; i++)
			{
				push_array_index(i);
				begin_deserialize_complex(name);
				value[i].deserialize(this);
				end_deserialize_complex(name);
				pop_array_index();
			}

			end_deserialize_complex_array(name);
		}
	}

	template <typename T>
	void deserialize_complex_array(const char* name, T** value, bool raw)
	{
		int size = begin_deserialize_complex_array(name);
		*value = new T[size];

		if (raw && is_raw_serializable())
			raw_deserialize(value, sizeof(T) * size);
		else
		{
			for (int i = 0; i < size; i++)
			{
				push_array_index(i);
				begin_deserialize_complex(name);
				*value[i].deserialize(this);
				end_deserialize_complex(name);
				pop_array_index();
			}

			end_deserialize_complex_array(name);
		}
	}

	// ----------------------------------------------------------
	// Reflection-based API
	// ----------------------------------------------------------

	inline void serialize(void* obj, TypeDescriptor_Struct* desc, bool trivial)
	{
		if (trivial && is_raw_serializable())
			raw_serialize(&obj, desc->m_size);
		else
		{
			char* ptr = static_cast<char*>(obj);

			for (int i = 0; i < desc->m_num_members; i++)
				desc->m_members[i].m_type->serialize(ptr + desc->m_members[i].m_offset, desc->m_members[i].m_name, this);
		}
	}

	template <typename T>
	void save(T& obj)
	{
		serialize(&obj, &T::Reflection, false);
	}

	inline void deserialize(void* obj, TypeDescriptor_Struct* desc, bool trivial)
	{
		if (trivial && is_raw_serializable())
			raw_deserialize(&obj, desc->m_size);
		else
		{
			char* ptr = static_cast<char*>(obj);

			for (int i = 0; i < desc->m_num_members; i++)
				desc->m_members[i].m_type->deserialize(ptr + desc->m_members[i].m_offset, desc->m_members[i].m_name, this);
		}
	}

	template <typename T>
	void load(T& obj)
	{
		deserialize(&obj, &T::Reflection, false);
	}

protected:
	std::stack<int> m_index_stack;
};

TE_END_TERMINUS_NAMESPACE