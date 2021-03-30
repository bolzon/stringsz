/////////////////////////////////////////////////////////////////////////////
//
// Stringsz.cpp: implementation of the CStringsz class.
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Stringsz.h"

/////////////////////////////////////////////////////////////////////////////
// CONSTRUCTOR/DESTRUCTOR
/////////////////////////////////////////////////////////////////////////////

CStringsz::CStringsz()
{
    Init();
}

CStringsz::CStringsz(const char* str)
{
    Init();
    SetBuffer(str);
}

CStringsz::CStringsz(UINT num)
{
    Init();
    SetBuffer(num);
}

CStringsz::~CStringsz()
{
    if (_buffer != NULL)
    {
        delete[] _buffer;
        _buffer = NULL;
    }
}

bool CStringsz::Compare(const char* str) const
{
    if (str == NULL)
    {
        return false;
    }

    return (strcmp(_buffer, str) == 0);
}

bool CompareNoCase(const char* str)
{
    // TODO: Compare with no case.

    return false;
}

void CStringsz::TrimLeft()
{
    const char space = ' ';
    if (_size > 0)
    {
        UINT i = 0;
        while (_buffer[i++] == space);
        SetBuffer(&_buffer[i - 1]);
    }
}

void CStringsz::TrimRight()
{
    const char space = ' ';
    if (_size > 0)
    {
        UINT i = _size;
        while (_buffer[--i] == space);
        _buffer[i + 1] = '\0';
        SetBuffer(_buffer);
    }
}

bool CStringsz::SetAt(UINT index, char ch)
{
    if ((index >= 0) && (index <= _size))
    {
        _buffer[index] = ch;
        return true;
    }

    return false;
}

char CStringsz::GetAt(UINT index) const
{
    char ch = 0;
    if ((index >= 0) && (index <= _size))
    {
        ch = _buffer[index];
    }

    return ch;
}

UINT CStringsz::GetLength() const
{
    return _size;
}

void CStringsz::operator= (const char* str)
{
    SetBuffer(str);
}

void CStringsz::operator= (UINT num)
{
    SetBuffer(num);
}

void CStringsz::operator+= (const char* str)
{
    Concat(str);
}

void CStringsz::operator+= (UINT num)
{
    Concat(num);
}

bool CStringsz::operator== (const char* str)
{
    return Compare(str);
}

char CStringsz::operator[] (UINT index)
{
    return GetAt(index);
}

const char* CStringsz::operator+ (const char* str)
{
    // TODO: Operator add

    return "\0";
}

const char* CStringsz::operator+ (UINT num)
{
    // TODO: Operator add

    return "\0";
}

CStringsz::operator LPCTSTR() const
{
    return _buffer;
}

/////////////////////////////////////////////////////////////////////////////
// PROTECTED METHODS
/////////////////////////////////////////////////////////////////////////////

void CStringsz::Concat(const char* str)
{
    char* concat = (char*) GetAlloc(str);
    if (concat != NULL)
    {
        UINT concatSize = strlen(concat);
        UINT fullSize = concatSize + _size;

        char* buffer = new char[fullSize + 1];
        if (buffer != NULL)
        {
            memset(buffer, 0, fullSize + 1);
            memcpy(buffer, _buffer, _size);
            memcpy(&buffer[_size], concat, concatSize);
            _size = fullSize;

            delete _buffer;
            _buffer = buffer;
        }

        delete[] concat;
    }
}

void CStringsz::Concat(UINT num)
{
    char* buffer = (char*) GetAlloc(num);
    if (buffer != NULL)
    {
        Concat(buffer);
        delete[] buffer;
    }
}

void CStringsz::SetBuffer(const char* str)
{
    char* buffer = (char*) GetAlloc(str);
    if (buffer != NULL)
    {
        if (_buffer != NULL)
        {
            delete[] _buffer;
        }

        _buffer = buffer;
        _size = strlen(_buffer);
    }
}

void CStringsz::SetBuffer(UINT num)
{
    char* buffer = (char*) GetAlloc(num);
    if (buffer != NULL)
    {
        if (_buffer != NULL)
        {
            delete[] _buffer;
        }

        _buffer = buffer;
        _size = strlen(_buffer);
    }
}

const char* CStringsz::GetAlloc(const char* str)
{
    char* buffer = NULL;
    if (str != NULL)
    {
        const UINT size = strlen(str);

        if (size > 0)
        {
            buffer = new char[size + 1];

            if (buffer != NULL)
            {
                memset(buffer, 0, size + 1);
                memcpy(buffer, str, size);
            }
        }
    }

    return buffer;
}

const char* CStringsz::GetAlloc(UINT num)
{
    UINT digits = 0;
    UINT numAux = num;

    while (numAux > 0)
    {
        digits++;
        numAux /= 10;
    }

    char* numStr = new char[digits + 1];
    if (numStr != NULL)
    {
        memset(numStr, 0, digits + 1);
        itoa(num, numStr, 10);
    }

    return numStr;
}

/////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
/////////////////////////////////////////////////////////////////////////////

void CStringsz::Init()
{
    _buffer = new char[1];
    _buffer[0] = '\0';
    _size = 0;
}

// End