/////////////////////////////////////////////////////////////////////////////
//
// Stringsz.h: interface for the CStringsz class.
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGSZ_H__CBE9C951_3280_443F_90EC_43510E6ED80E__INCLUDED_)
#define AFX_STRINGSZ_H__CBE9C951_3280_443F_90EC_43510E6ED80E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string.h>
#include <windows.h>

class CStringsz
{
public:

    /*
    bool Delete(int start, int count = 1);
    Empty();
    Find(const char* str, int inicio = 0);
    Format(const char* format, ...);
    GetBuffer(int maxBuffer = 0);
    Insert(int inicio, const char* str);
    IsEmpty();
    MakeLower();
    MakeReverse();
    MakeUpper();
    Mid(int first);
    Mid(int first, int count);
    ReleaseBuffer();
    Remove();
    Replace(const char* old, const char* new);
    ReverseFind(char ch);
    */

    CStringsz();
    CStringsz(const char* str);
    CStringsz(UINT num);
    ~CStringsz();

    bool Compare(const char* str) const;
    bool CompareNoCase(const char* str) const;
    void TrimLeft();
    void TrimRight();
    bool SetAt(UINT index, char ch);
    char GetAt(UINT index) const;
    UINT GetLength() const;

    void operator= (const char* str);
    void operator= (UINT num);
    void operator+= (const char* str);
    void operator+= (UINT num);
    bool operator== (const char* str);
    char operator[] (UINT index);
    const char* operator+ (const char* str);
    const char* operator+ (UINT num);
    operator LPCTSTR() const;

protected:

    void Concat(UINT num);
    void Concat(const char* str);
    void SetBuffer(const char* str);
    void SetBuffer(UINT num);
    const char* GetAlloc(const char* str);
    const char* GetAlloc(UINT num);

private:

    void Init();

    UINT _size;
    char* _buffer;
};

#endif // !defined(AFX_STRINGSZ_H__CBE9C951_3280_443F_90EC_43510E6ED80E__INCLUDED_)

// End