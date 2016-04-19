

/* epan/tvbuff-int.h */
typedef struct tvbuff tvbuff_t;
struct tvbuff {
	tvbuff_t                *next; /* Doubly linked list pointers */

	/* Record-keeping */
	const struct tvb_ops   *ops;
	gboolean		initialized;
	guint			flags;
	struct tvbuff		*ds_tvb;  /**< data source top-level tvbuff */

	const guint8		*real_data;
	
	guint			length; /** Length of virtual buffer (and/or real_data). */
	guint			reported_length; /** Reported length. */
	gint			raw_offset; /* Offset from beginning of first TVBUFF_REAL. */
};





/* epan/packet_info.h */
typedef struct _packet_info {
  const char *current_proto;        /**< name of protocol currently being dissected */
  struct epan_column_info *cinfo;   /**< Column formatting information */
  guint32 presence_flags;           /**< Presence flags for some items */
  guint32 num;                      /**< Frame number */
  nstime_t abs_ts;                  /**< Packet absolute time stamp */
  nstime_t rel_ts;                  /**< Relative timestamp (yes, it can be negative) */
  gint pkt_encap;                   /**< Per-packet encapsulation/data-link type */
  frame_data *fd;
  union wtap_pseudo_header *pseudo_header;
  struct wtap_pkthdr *phdr;         
  GSList *data_src;                 
  address dl_src;                   
  address dl_dst;                   
  address net_src;                  
  address net_dst;                  
  address src;                      
  address dst;                      
  guint32 vlan_id;                  
  circuit_type ctype;               
  guint32 circuit_id;               
  const char *noreassembly_reason;  
  gboolean fragmented;              
  struct {
    guint32 in_error_pkt:1;         
    guint32 in_gre_pkt:1;           
  } flags;
  port_type ptype;                  
  guint32 srcport;                  
  guint32 destport;                 
  guint32 match_uint;               
  const char *match_string;         
  guint16 can_desegment;            
  guint16 saved_can_desegment;      
  int desegment_offset;             
#define DESEGMENT_ONE_MORE_SEGMENT 0x0fffffff
#define DESEGMENT_UNTIL_FIN        0x0ffffffe
  guint32 desegment_len;    
  guint16 want_pdu_tracking; 
  guint32 bytes_until_next_pdu;

  int     p2p_dir;  

  GHashTable *private_table;    /**< a hash table passed from one dissector to another */

  wmem_list_t *layers;          /**< layers of each protocol */
  guint8 curr_layer_num;       /**< The current "depth" or layer number in the current frame */
  guint16 link_number;

  guint16 clnp_srcref;          /**< clnp/cotp source reference (can't use srcport, this would confuse tpkt) */
  guint16 clnp_dstref;          /**< clnp/cotp destination reference (can't use dstport, this would confuse tpkt) */

  int link_dir;                 /**< 3GPP messages are sometime different UP link(UL) or Downlink(DL) */

  GSList* proto_data;          /**< Per packet proto data */
  GSList* dependent_frames;     /**< A list of frames which this one depends on */
  GSList* frame_end_routines;

  wmem_allocator_t *pool;      /**< Memory pool scoped to the pinfo struct */
  struct epan_session *epan;
  const gchar *heur_list_name;    /**< name of heur list if this packet is being heuristically dissected */
} packet_info;





typedef proto_node proto_tree;
typedef struct _proto_node {
	struct _proto_node *first_child;
	struct _proto_node *last_child;
	struct _proto_node *next;
	struct _proto_node *parent;
	field_info  *finfo;
	tree_data_t *tree_data;
} proto_node;




