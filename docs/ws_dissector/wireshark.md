# C++によるWiresharkのdissector開発について

wiresharkはスクリプト言語luaで簡単にdissectorプラグインを追加することができる。
これについての日本語の情報は結構あるのだが、c++でのdissector開発に関しての
日本語情報が少なかったので、英語(できない)の情報を調べながら簡単なdissectorを
書いてみることにした。



## Dissector開発の流れ

C++によるDissectorの開発は以下の作業が必要

 1. cppファイルなどの必要なファイルの追加
 1. 必要な変数や関数の宣言と定義

wiresharkの仕組みを最低限知っている必要はあるが、やるだけの内容ではあるので
わかってしまえば後は簡単。（だといいなあ）
今回は簡単なプロコルを定義してそのパケットをwiresharkで解析できるように
してみようと思います。

プラグインは共有ライブラリのファイルとして出来上がり
plugins/NAME/.lib/以下に実行ファイルが置かれる。



### 必要なファイルの準備

コンパイルには以下のファイルが必要。wireshark/plugins以下を作業ディレクトリとします。

| name            | description                          |                                                             |
|:---------------:|:-------------------------------------|:------------------------------------------------------------|
| Makefile.am     | Makefile                             | gryphonのdissectorを参考にする                              |
| Makefile.common | プラグインのファイル名を書くMakefile | gryphonのdissectorを参考にする                              |
| CMakeList.txt   | Cmakefile                            | トップディレクトリのCMakeCustomList.txt.exampleを参考にする |
| moduleinfo.h    | プラグインのバージョン情報           | 他のdissectorを参考にする (数行程度)                        |
| packet-XXX.c    | dissectorのソースコード              | 後述                                                        |
| plugin.rc.in    | DLLリーソス情報 (Win用?)             | gryphonのdissectorを参考にする                              |

packet-XXX.c以外はすぐに準備ができるはずです。また、最低限makeをする為に以下のファイルを編集します。

 - configure.ac
 - Makefile.am
 - plugins/Makefile.am
 - plugins/Makefile.nmake


### 必要な関数の実装

packet-XXX.cの実装をあとはするだけです。このファイルは以下の関数の実装が必要です。

| func name              | description                                                                                   |
|:----------------------:|:----------------------------------------------------------------------------------------------|
| proto_register_XXX     | 初期化作業 |
| proto_reg_handleff_XXX | dissectorオブジェクトの確保とそのポインタとプロトコルのハンドルを結びつける           |


これらの実装には以下の関数を使用します。

| func name               | description                                                                   |
|:-----------------------:|:------------------------------------------------------------------------------|
| proto_register_protocol | 新たなプロトコルを登録する  |
| create_dissector        | dissectorハンドルを作成する |
| dissector_add_uint      | フィルタと結びつける |

create_dissector()は具体的には内部でdissector一つをまとめて管理する構造体のメモリを確保してそのポインタを返している。

create_dissector()は
```
dissector_handle_t create_dissector_handle(dissector_t dissector, const int proto);
```
として宣言されていて、dissector_handle_tは
```
typedef struct dissector_handle *dissector_handle_t;

struct dissector_handle {
	const char	*name;		/* dissector name */
	dissector_t	dissector;
	protocol_t	*protocol;
};
```
となっている

packet_info型はepan/packet_info.hで定義されている.


### dissect_XXX()について


```
static int dissect_XXX(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data);
```

 - tvbuff_t* tvb 実際のパケットのデータポインタを持つ構造体
 - packet_info* pinfo パケットの基本情報構造体のポインタ (tstampからsrc.ipとかまで)
 - proto_tree* tree  何かの木構造
 - void* data



### でてくる構造体などについて

#### hf_register_info構造体

HeaderField Register Information Structure

epan/proto.h

```
typedef struct hf_register_info {
	int				*p_id;	/**< written to by register() function */
	header_field_info		hfinfo;	/**< the field info to be registered */
} hf_register_info;
```

#### header_field_info構造体

```
struct _header_field_info {
	/* ---------- set by dissector --------- */
	const char		*name;      
	const char		*abbrev;   
	enum ftenum		 type;     
	int			 display;      
	const void		*strings;  

	guint64			 bitmask;    
	const char		*blurb;      

	/* ------- set by proto routines (prefilled by HFILL macro, see below) ------ */
	int				     id;                /**< Field ID */
	int					 parent;            /**< parent protocol tree */
	hf_ref_type			 ref_type;          /**< is this field referenced by a filter */
	int                  same_name_prev_id; /**< ID of previous hfinfo with same abbrev */
	header_field_info	*same_name_next;    /**< Link to next hfinfo with same abbrev */
};
```


### dissecor のサンプルコード

```
```
