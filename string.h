//string.h

/*void *memchr(const void *s, int c, size_t n);
*The memchr() function locates the ﬁrst occurrence of c (converted to an unsigned char) in the initial n characters (each interpreted as unsigned char) of the object pointed to by s.
*/
#include <stddef.h>
void *memchr(const void *s, int c, size_t n)
{
    unsigned char *p = (unsigned char*)s;
    while( n-- )
        if( *p != (unsigned char)c )
            p++;
        else
            return p;
    return 0;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
**The memcmp() function returns an integer greater than, equal to, or less than zero, accordingly as the object pointed to by s1 is greater than, equal to, or less than the object pointed to by s2.
*/
#include <stddef.h> /* size_t */
int memcmp(const void* s1, const void* s2,size_t n)
{
    const unsigned char *p1 = s1, *p2 = s2;
    while(n--)
        if( *p1 != *p2 )
            return *p1 - *p2;
        else
            p1++,p2++;
    return 0;
}

/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
he memcpy() function shall return the pointer dest; the function has no failure mode and no error return.
*/
#include <stddef.h> /* size_t */
void *memcpy(void *dest, const void *src, size_t n)
{
    char *dp = dest;
    const char *sp = src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The memmove() function shall return the pointer dest; the function has no failure mode and no error return.
*/
#include <stddef.h> /* for size_t */
void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *pd = dest;
    const unsigned char *ps = src;
    if (__np_anyptrlt(ps, pd))
        for (pd += n, ps += n; n--;)
            *--pd = *--ps;
    else
        while(n--)
            *pd++ = *ps++;
    return dest;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The memset function copies the value of c (converted to an unsigned char) into each of the ﬁrst n characters of the object pointed to by s.
*/
#include <stddef.h> /* size_t */
void *memset(void *s, int c, size_t n)
{
    unsigned char* p=s;
    while(n--)
        *p++ = (unsigned char)c;
    return s;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strcat() function shall return the pointer dest; the function has no failure mode and no error return.
*/
#include <string.h> /* for strlen() */
char *strcat(char *dest, const char *src)
{
    char *ret = dest;
    dest += strlen(dest);
    while (*dest++ = *src++)
        ;
    return ret;
}



/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strchr() function returns a pointer to the located character, or a null pointer if the character does not occur in the string.
*/
char *strchr(const char *s, int c)
{
    while (*s != (char)c)
        if (!*s++)
            return 0;
    return (char *)s;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strcmp() function returns an integer greater than, equal to, or less than zero, accordingly as the string pointed to by s1 is greater than, equal to, or less than the string pointed to by s2.
*/
int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}




/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strcpy() function shall return the pointer dest; the function has no failure mode and no error return.
*/
//char *strcpy(char *dest, const char* src)
#ifdef _NC_RESTRICT
char *strcpy(char *restrict dest, const char *restrict src)
#else
char *strcpy(char *dest, const char* src)
#endif
{
    char *ret = dest;
    while (*dest++ = *src++)
        ;
    return ret;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strlen() function shall return the length of s; the function has no failure mode and no error return.
*/
#include <stddef.h> /* for size_t */
size_t strlen(const char *s) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) ;
    return i;
}

#include <stddef.h> /* for size_t */
size_t strlen(const char *s) {
    const char *p = s;
    while (*s) ++s;
    return s - p;
}


/*  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *
The strncat() function shall return the pointer dest; the function has no failure mode and no error return.
*/
#include <stddef.h> /* size_t */
char *strncat(char *dest, const char *src, size_t n)
{
    char *ret = dest;
    while (*dest)
        dest++;
    while (n--)
        if (!(*dest++ = *src++))
            return ret;
    *dest = 0;
    return ret;
}


/**  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *  *  *   *  *

*/



/*

*/
