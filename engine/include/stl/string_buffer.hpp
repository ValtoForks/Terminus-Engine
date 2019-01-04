#pragma once

#include <stdio.h>
#include <cstring>
#include <string>

template<size_t SIZE>
class StringBuffer
{
private:
    char   _buffer[SIZE];
    size_t _length;
    
public:
    const static size_t END = SIZE;
    
public:
    StringBuffer()
    {
        _length = 0;
    }
    
    StringBuffer(const char* str)
    {
        strcpy(&_buffer[0], str);
        _length = strlen(str);
    }
    
    StringBuffer(std::string str)
    {
        strcpy(&_buffer[0], str.c_str());
        _length = strlen(str.c_str());
    }
    
    inline size_t find_first(char c) const
    {
        for(int i = 0; i < _length; i++)
        {
            if(_buffer[i] == c)
                return i;
        }
        
        return END;
    }
    
    inline size_t find_last(char c) const
    {
        size_t pos = END;
        
        for(int i = 0; i < _length; i++)
        {
            if(_buffer[i] == c)
                pos = i;
        }
        
        return pos;
    }
    
    inline size_t size() const
    {
        return SIZE;
    }
    
    inline StringBuffer substring(size_t start, size_t end) const
    {
        StringBuffer buf;
        
        if(end == END)
            end = _length - 1;
        
        buf._length = end - start + 1;
        strncpy(&buf._buffer[0], &_buffer[start], buf._length);
        buf._buffer[buf._length] = '\0';
        
        return buf;
    }
    
    inline const char* c_str() const { return &_buffer[0]; }
    
    inline size_t length() const { return _length; }
    
    StringBuffer& operator = (const StringBuffer& buf)
    {
        strcpy(&this->_buffer[0], &buf._buffer[0]);
        this->_length = buf._length;
        return *this;
    }
    
    void operator = (const char* buf)
    {
        strcpy(&this->_buffer[0], buf);
        this->_length = strlen(buf);
    }
    
    StringBuffer& operator+ (const StringBuffer& buf)
    {
        if(this->_length + buf._length < SIZE)
        {
            strcpy(&this->_buffer[this->_length], &buf._buffer[0]);
            this->_length += buf._length;
        }
        
        return *this;
    }
    
    StringBuffer& operator += (const StringBuffer& buf)
    {
        return *this + buf;
    }
    
    bool operator == (const char* str)
    {
        return (strcmp(this->c_str(), str) == 0);
    }
    
    bool operator != (const char* str)
    {
        return (strcmp(this->c_str(), str) != 0);
    }
    
    bool operator == (StringBuffer& buf)
    {
        return (strcmp(this->c_str(), buf.c_str()) == 0);
    }

	bool operator == (const StringBuffer& buf)
	{
		return (strcmp(this->c_str(), buf.c_str()) == 0);
	}
    
    bool operator != (StringBuffer& buf)
    {
        return (strcmp(this->c_str(), buf.c_str()) != 0);
    }
    
};

using StringBuffer16  = StringBuffer<16>;
using StringBuffer32  = StringBuffer<32>;
using StringBuffer64  = StringBuffer<64>;
using StringBuffer128 = StringBuffer<128>;
using StringBuffer256 = StringBuffer<256>;
