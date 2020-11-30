# sqlite3加解密接口实现

## sqlite3源码获取
<https://www.sqlite.org/amalgamation.html><br/>
3.31版本之后sqlite源码去除了SQLITE_HAS_CODEC以及相关加解密接口，改为使用VFS实现加解密功能<br/>
<https://sqlite.org/2020/sqlite-amalgamation-3310100.zip><br/>

## 设置SQLITE_HAS_CODEC
在vs对应工程 属性->C/C++->预处理器->预处理器定义中添加 SQLITE_HAS_CODEC<br/>
在 sqlite3.h 头文件中添加:<br/>
\#ifndef SQLITE_HAS_CODEC<br/>
\#define SQLITE_HAS_CODEC<br/>
\#endif<br/>

## 链接找不到的接口(需要实现的接口)
unresolved external symbol sqlite3_key_v2 referenced in function sqlite3CodecQueryParameters<br/>
unresolved external symbol sqlite3_rekey_v2 referenced in function sqlite3Pragma<br/>
unresolved external symbol sqlite3_activate_see referenced in function sqlite3Pragma<br/>
unresolved external symbol sqlite3CodecAttach referenced in function attachFunc<br/>
unresolved external symbol sqlite3CodecGetKey referenced in function attachFunc<br/>

## Pager Reserve相关api 位于源码btree.h
int sqlite3BtreeSetPageSize(Btree *p, int nPagesize, int nReserve, int eFix);<br/>
int sqlite3BtreeGetRequestedReserve(Btree*);<br/>
int sqlite3BtreeGetReserveNoMutex(Btree *p);<br/>

## Pager 设置以及获取Codec api
void sqlite3PagerSetCodec(
  Pager *pPager,
  void *(*xCodec)(void*,void*,Pgno,int),
  void (*xCodecSizeChng)(void*,int,int),
  void (*xCodecFree)(void*),
  void *pCodec
);<br/>
void *sqlite3PagerGetCodec(Pager *pPager);<br/>

## 说明
自己添加的代码位于sqlite3.c文件尾部<br/>
<br/>
参考文章<br/>
<https://www.jianshu.com/p/208200e0c465><br/>
<http://blog.sina.com.cn/s/blog_648d306d0101jzvo.html><br/>
