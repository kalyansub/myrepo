#ifndef C_WRAPPER_H
#define C_WRAPPER_H

/* This header file can be included in both C++ and C code ... */
#ifndef __cplusplus
typedef enum {false, true} bool;
#endif
#ifdef __cplusplus
   extern "C" {
#endif

  typedef struct Deque   Deque;
  /* opaque object pointer */

  Deque* create_Deque( ) ;
  void destroy_Deque( Deque* This ) ;
  void InsertFront(Deque* This, int element);
  int RemoveFront(Deque* This);
  void InsertBack(Deque* This, int element);
  int RemoveBack(Deque* This);
  int Front(Deque* This);
  int Back(Deque* This);
  int Size(Deque* This);
  bool isEmpty(Deque* This);
#ifdef __cplusplus
   }
#endif

#endif /* C_WRAPPER_H */
