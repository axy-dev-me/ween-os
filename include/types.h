#ifndef TYPES_H
#define TYPES_H

typedef __typeof__(sizeof(int))     size_t;
typedef unsigned char               uint8_t;
typedef unsigned short              uint16_t;
typedef unsigned int                uint32_t;

#define __sil_int      static inline int
#define __sil_char     static inline char
#define __sil_size_t   static inline size_t
#define __sil_uint8_t  static inline uint8_t
#define __sil_uint16_t static inline uint16_t
#define __sil_uint32_t static inline uint32_t
#define __sil_void     static inline void

#endif