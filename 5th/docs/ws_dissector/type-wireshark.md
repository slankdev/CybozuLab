# Wiresharkコードリーディングメモ




## 関数などについて

### dissect_XXX()について (自分で実装)

```
static int dissect_XXX(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data);
```

 - tvbuff_t* tvb 実際のパケットのデータポインタを持つ構造体
 - packet_info* pinfo パケットの基本情報構造体のポインタ (tstampからsrc.ipとかまで)
 - proto_tree* tree  何かの木構造
 - void* data


### proto_tree_add_item()

```
```








## 構造体などについて

### hf_register_info構造体

HeaderField Register Information Structure

epan/proto.h

```
typedef struct hf_register_info hf_register_info;
struct hf_register_info {
	int		          *p_id;   /* written to by register() function */
	header_field_info hfinfo;  /* the field info to be registered   */
};
```


### header_field_info構造体

This structure is wrapped by hf_register_info.

epan/proto.h

```
struct _header_field_info {
	/* ---------- set by dissector --------- */
	const char		*name;    /* full name of this field          */
	const char		*abbrev;  /* abbrev name of this field        */
	enum ftenum		 type;    /* field type, one of FT_(ftypes.h) */
	int			 display;     /* one of BASE_, or field bit-width */
	const void		*strings; /* value_string                     */
 
	guint64			 bitmask; /* bitmask of interesting bit       */
	const char		*blurb;   /* brief description of field       */

	/* ------- set by proto routines (prefilled by HFILL macro, see below) ------ */
	int				     id;                /**< Field ID */
	int					 parent;            /**< parent protocol tree */
	hf_ref_type			 ref_type;          /**< is this field referenced by a filter */
	int                  same_name_prev_id; /**< ID of previous hfinfo with same abbrev */
	header_field_info	*same_name_next;    /**< Link to next hfinfo with same abbrev */
};
```





