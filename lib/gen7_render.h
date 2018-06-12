#ifndef GEN7_RENDER_H
#define GEN7_RENDER_H

#include <stdint.h>
#include "surfaceformat.h"
#include "gen6_render.h"

#define INTEL_MASK(high, low) (((1 << ((high) - (low) + 1)) - 1) << (low))

#define GEN7_3D(Pipeline,Opcode,Subopcode) ((3 << 29) | \
					   ((Pipeline) << 27) | \
					   ((Opcode) << 24) | \
					   ((Subopcode) << 16))

#define GEN7_STATE_BASE_ADDRESS			GEN7_3D(0, 1, 1)
#define GEN7_STATE_SIP				GEN7_3D(0, 1, 2)

#define GEN7_PIPELINE_SELECT			GEN7_3D(1, 1, 4)

#define GEN7_MEDIA_STATE_POINTERS		GEN7_3D(2, 0, 0)
#define GEN7_MEDIA_OBJECT			GEN7_3D(2, 1, 0)

#define GEN7_3DSTATE_VERTEX_BUFFERS		GEN7_3D(3, 0, 8)
#define GEN7_3DSTATE_VERTEX_ELEMENTS		GEN7_3D(3, 0, 9)
#define GEN7_3DSTATE_INDEX_BUFFER		GEN7_3D(3, 0, 0xa)
#define GEN7_3DSTATE_VF_STATISTICS		GEN7_3D(3, 0, 0xb)

#define GEN7_3DSTATE_DRAWING_RECTANGLE		GEN7_3D(3, 1, 0)
#define GEN7_3DSTATE_CONSTANT_COLOR		GEN7_3D(3, 1, 1)
#define GEN7_3DSTATE_SAMPLER_PALETTE_LOAD	GEN7_3D(3, 1, 2)
#define GEN7_3DSTATE_CHROMA_KEY			GEN7_3D(3, 1, 4)

#define GEN7_3DSTATE_POLY_STIPPLE_OFFSET		GEN7_3D(3, 1, 6)
#define GEN7_3DSTATE_POLY_STIPPLE_PATTERN	GEN7_3D(3, 1, 7)
#define GEN7_3DSTATE_LINE_STIPPLE		GEN7_3D(3, 1, 8)
#define GEN7_3DSTATE_GLOBAL_DEPTH_OFFSET_CLAMP	GEN7_3D(3, 1, 9)
/* These two are BLC and CTG only, not BW or CL */
#define GEN7_3DSTATE_AA_LINE_PARAMS		GEN7_3D(3, 1, 0xa)
#define GEN7_3DSTATE_GS_SVB_INDEX		GEN7_3D(3, 1, 0xb)

#define GEN7_3DPRIMITIVE				GEN7_3D(3, 3, 0)

#define GEN7_3DSTATE_SAMPLER_STATE_POINTERS	GEN7_3D(3, 0, 0x02)
# define GEN7_3DSTATE_SAMPLER_STATE_MODIFY_PS	(1 << 12)
# define GEN7_3DSTATE_SAMPLER_STATE_MODIFY_GS	(1 << 9)
# define GEN7_3DSTATE_SAMPLER_STATE_MODIFY_VS	(1 << 8)

#define GEN7_3DSTATE_URB			GEN7_3D(3, 0, 0x05)
/* DW1 */
# define GEN7_3DSTATE_URB_VS_SIZE_SHIFT		16
# define GEN7_3DSTATE_URB_VS_ENTRIES_SHIFT	0
/* DW2 */
# define GEN7_3DSTATE_URB_GS_ENTRIES_SHIFT	8
# define GEN7_3DSTATE_URB_GS_SIZE_SHIFT		0

#define GEN7_3DSTATE_VIEWPORT_STATE_POINTERS	GEN7_3D(3, 0, 0x0d)
# define GEN7_3DSTATE_VIEWPORT_STATE_MODIFY_CC		(1 << 12)
# define GEN7_3DSTATE_VIEWPORT_STATE_MODIFY_SF		(1 << 11)
# define GEN7_3DSTATE_VIEWPORT_STATE_MODIFY_CLIP	(1 << 10)

#define GEN7_3DSTATE_CC_STATE_POINTERS		GEN7_3D(3, 0, 0x0e)

#define GEN7_3DSTATE_VS				GEN7_3D(3, 0, 0x10)

#define GEN7_3DSTATE_GS				GEN7_3D(3, 0, 0x11)
/* DW4 */
# define GEN7_3DSTATE_GS_DISPATCH_START_GRF_SHIFT	0

#define GEN7_3DSTATE_CLIP			GEN7_3D(3, 0, 0x12)

#define GEN7_3DSTATE_SF				GEN7_3D(3, 0, 0x13)
/* DW1 */
# define GEN7_3DSTATE_SF_NUM_OUTPUTS_SHIFT		22
# define GEN7_3DSTATE_SF_URB_ENTRY_READ_LENGTH_SHIFT	11
# define GEN7_3DSTATE_SF_URB_ENTRY_READ_OFFSET_SHIFT	4
/* DW2 */
/* DW3 */
# define GEN7_3DSTATE_SF_CULL_BOTH			(0 << 29)
# define GEN7_3DSTATE_SF_CULL_NONE			(1 << 29)
# define GEN7_3DSTATE_SF_CULL_FRONT			(2 << 29)
# define GEN7_3DSTATE_SF_CULL_BACK			(3 << 29)
/* DW4 */
# define GEN7_3DSTATE_SF_TRI_PROVOKE_SHIFT		29
# define GEN7_3DSTATE_SF_LINE_PROVOKE_SHIFT		27
# define GEN7_3DSTATE_SF_TRIFAN_PROVOKE_SHIFT		25

#define GEN7_3DSTATE_WM				GEN7_3D(3, 0, 0x14)
/* DW1 */
# define GEN7_WM_STATISTICS_ENABLE                              (1 << 31)
# define GEN7_WM_DEPTH_CLEAR                                    (1 << 30)
# define GEN7_WM_DISPATCH_ENABLE                                (1 << 29)
# define GEN7_WM_DEPTH_RESOLVE                                  (1 << 28)
# define GEN7_WM_HIERARCHICAL_DEPTH_RESOLVE                     (1 << 27)
# define GEN7_WM_KILL_ENABLE                                    (1 << 25)
# define GEN7_WM_PSCDEPTH_OFF                                   (0 << 23)
# define GEN7_WM_PSCDEPTH_ON                                    (1 << 23)
# define GEN7_WM_PSCDEPTH_ON_GE                                 (2 << 23)
# define GEN7_WM_PSCDEPTH_ON_LE                                 (3 << 23)
# define GEN7_WM_USES_SOURCE_DEPTH                              (1 << 20)
# define GEN7_WM_USES_SOURCE_W                                  (1 << 19)
# define GEN7_WM_POSITION_ZW_PIXEL                              (0 << 17)
# define GEN7_WM_POSITION_ZW_CENTROID                           (2 << 17)
# define GEN7_WM_POSITION_ZW_SAMPLE                             (3 << 17)
# define GEN7_WM_NONPERSPECTIVE_SAMPLE_BARYCENTRIC              (1 << 16)
# define GEN7_WM_NONPERSPECTIVE_CENTROID_BARYCENTRIC            (1 << 15)
# define GEN7_WM_NONPERSPECTIVE_PIXEL_BARYCENTRIC               (1 << 14)
# define GEN7_WM_PERSPECTIVE_SAMPLE_BARYCENTRIC                 (1 << 13)
# define GEN7_WM_PERSPECTIVE_CENTROID_BARYCENTRIC               (1 << 12)
# define GEN7_WM_PERSPECTIVE_PIXEL_BARYCENTRIC                  (1 << 11)
# define GEN7_WM_USES_INPUT_COVERAGE_MASK                       (1 << 10)
# define GEN7_WM_LINE_END_CAP_AA_WIDTH_0_5                      (0 << 8)
# define GEN7_WM_LINE_END_CAP_AA_WIDTH_1_0                      (1 << 8)
# define GEN7_WM_LINE_END_CAP_AA_WIDTH_2_0                      (2 << 8)
# define GEN7_WM_LINE_END_CAP_AA_WIDTH_4_0                      (3 << 8)
# define GEN7_WM_LINE_AA_WIDTH_0_5                              (0 << 6)
# define GEN7_WM_LINE_AA_WIDTH_1_0                              (1 << 6)
# define GEN7_WM_LINE_AA_WIDTH_2_0                              (2 << 6)
# define GEN7_WM_LINE_AA_WIDTH_4_0                              (3 << 6)
# define GEN7_WM_POLYGON_STIPPLE_ENABLE                         (1 << 4)
# define GEN7_WM_LINE_STIPPLE_ENABLE                            (1 << 3)
# define GEN7_WM_POINT_RASTRULE_UPPER_RIGHT                     (1 << 2)
# define GEN7_WM_MSRAST_OFF_PIXEL                               (0 << 0)
# define GEN7_WM_MSRAST_OFF_PATTERN                             (1 << 0)
# define GEN7_WM_MSRAST_ON_PIXEL                                (2 << 0)
# define GEN7_WM_MSRAST_ON_PATTERN                              (3 << 0)
/* DW2 */
# define GEN7_WM_MSDISPMODE_PERPIXEL                            (1 << 31)


#define GEN7_3DSTATE_CONSTANT_VS		GEN7_3D(3, 0, 0x15)
#define GEN7_3DSTATE_CONSTANT_GS		GEN7_3D(3, 0, 0x16)
#define GEN7_3DSTATE_CONSTANT_PS		GEN7_3D(3, 0, 0x17)

#define GEN7_3DSTATE_SAMPLE_MASK		GEN7_3D(3, 0, 0x18)

#define GEN7_3DSTATE_MULTISAMPLE		GEN7_3D(3, 1, 0x0d)
/* DW1 */
# define GEN7_3DSTATE_MULTISAMPLE_PIXEL_LOCATION_CENTER		(0 << 4)
# define GEN7_3DSTATE_MULTISAMPLE_PIXEL_LOCATION_UPPER_LEFT	(1 << 4)
# define GEN7_3DSTATE_MULTISAMPLE_NUMSAMPLES_1			(0 << 1)
# define GEN7_3DSTATE_MULTISAMPLE_NUMSAMPLES_4			(2 << 1)
# define GEN7_3DSTATE_MULTISAMPLE_NUMSAMPLES_8			(3 << 1)

#define PIPELINE_SELECT_3D		0
#define PIPELINE_SELECT_MEDIA		1

/* for GEN7_STATE_BASE_ADDRESS */
#define BASE_ADDRESS_MODIFY		(1 << 0)

/* for GEN7_PIPE_CONTROL */
#define GEN7_PIPE_CONTROL			GEN7_3D(3, 2, 0)
#define GEN7_PIPE_CONTROL_CS_STALL      (1 << 20)
#define GEN7_PIPE_CONTROL_NOWRITE       (0 << 14)
#define GEN7_PIPE_CONTROL_WRITE_QWORD   (1 << 14)
#define GEN7_PIPE_CONTROL_WRITE_DEPTH   (2 << 14)
#define GEN7_PIPE_CONTROL_WRITE_TIME    (3 << 14)
#define GEN7_PIPE_CONTROL_DEPTH_STALL   (1 << 13)
#define GEN7_PIPE_CONTROL_WC_FLUSH      (1 << 12)
#define GEN7_PIPE_CONTROL_IS_FLUSH      (1 << 11)
#define GEN7_PIPE_CONTROL_TC_FLUSH      (1 << 10)
#define GEN7_PIPE_CONTROL_NOTIFY_ENABLE (1 << 8)
#define GEN7_PIPE_CONTROL_GLOBAL_GTT    (1 << 2)
#define GEN7_PIPE_CONTROL_LOCAL_PGTT    (0 << 2)
#define GEN7_PIPE_CONTROL_STALL_AT_SCOREBOARD   (1 << 1)
#define GEN7_PIPE_CONTROL_DEPTH_CACHE_FLUSH	(1 << 0)

/* VERTEX_BUFFER_STATE Structure */
#define GEN7_VB0_BUFFER_INDEX_SHIFT	26
#define GEN7_VB0_VERTEXDATA		(0 << 20)
#define GEN7_VB0_INSTANCEDATA		(1 << 20)
#define GEN7_VB0_BUFFER_PITCH_SHIFT	0
#define GEN7_VB0_NULL_VERTEX_BUFFER	(1 << 13)
#define GEN7_VB0_ADDRESS_MODIFY_ENABLE	(1 << 14)

/* VERTEX_ELEMENT_STATE Structure */
#define GEN7_VE0_VERTEX_BUFFER_INDEX_SHIFT		26
#define GEN7_VE0_VALID					(1 << 25)
#define GEN7_VE0_FORMAT_SHIFT				16
#define GEN7_VE0_OFFSET_SHIFT				0
#define GEN7_VE1_VFCOMPONENT_0_SHIFT			28
#define GEN7_VE1_VFCOMPONENT_1_SHIFT			24
#define GEN7_VE1_VFCOMPONENT_2_SHIFT			20
#define GEN7_VE1_VFCOMPONENT_3_SHIFT			16
#define GEN7_VE1_DESTINATION_ELEMENT_OFFSET_SHIFT	0

/* 3DPRIMITIVE bits */
#define GEN7_3DPRIMITIVE_VERTEX_SEQUENTIAL (0 << 15)
#define GEN7_3DPRIMITIVE_VERTEX_RANDOM	  (1 << 15)

#define GEN7_SVG_CTL		       0x7400

#define GEN7_SVG_CTL_GS_BA	       (0 << 8)
#define GEN7_SVG_CTL_SS_BA	       (1 << 8)
#define GEN7_SVG_CTL_IO_BA	       (2 << 8)
#define GEN7_SVG_CTL_GS_AUB	       (3 << 8)
#define GEN7_SVG_CTL_IO_AUB	       (4 << 8)
#define GEN7_SVG_CTL_SIP		       (5 << 8)

#define GEN7_VF_CTL_SNAPSHOT_COMPLETE		   (1 << 31)
#define GEN7_VF_CTL_SNAPSHOT_MUX_SELECT_THREADID	   (0 << 8)
#define GEN7_VF_CTL_SNAPSHOT_MUX_SELECT_VF_DEBUG	   (1 << 8)
#define GEN7_VF_CTL_SNAPSHOT_TYPE_VERTEX_SEQUENCE   (0 << 4)
#define GEN7_VF_CTL_SNAPSHOT_TYPE_VERTEX_INDEX	   (1 << 4)
#define GEN7_VF_CTL_SKIP_INITIAL_PRIMITIVES	   (1 << 3)
#define GEN7_VF_CTL_MAX_PRIMITIVES_LIMIT_ENABLE	   (1 << 2)
#define GEN7_VF_CTL_VERTEX_RANGE_LIMIT_ENABLE	   (1 << 1)
#define GEN7_VF_CTL_SNAPSHOT_ENABLE		   (1 << 0)

#define GEN7_VF_STRG_VAL		       0x7504
#define GEN7_VF_STR_VL_OVR	       0x7508
#define GEN7_VF_VC_OVR		       0x750c
#define GEN7_VF_STR_PSKIP	       0x7510
#define GEN7_VF_MAX_PRIM		       0x7514
#define GEN7_VF_RDATA		       0x7518

#define GEN7_VS_CTL		       0x7600
#define GEN7_VS_CTL_SNAPSHOT_COMPLETE		   (1 << 31)
#define GEN7_VS_CTL_SNAPSHOT_MUX_VERTEX_0	   (0 << 8)
#define GEN7_VS_CTL_SNAPSHOT_MUX_VERTEX_1	   (1 << 8)
#define GEN7_VS_CTL_SNAPSHOT_MUX_VALID_COUNT	   (2 << 8)
#define GEN7_VS_CTL_SNAPSHOT_MUX_VS_KERNEL_POINTER  (3 << 8)
#define GEN7_VS_CTL_SNAPSHOT_ALL_THREADS		   (1 << 2)
#define GEN7_VS_CTL_THREAD_SNAPSHOT_ENABLE	   (1 << 1)
#define GEN7_VS_CTL_SNAPSHOT_ENABLE		   (1 << 0)

#define GEN7_VS_STRG_VAL		       0x7604
#define GEN7_VS_RDATA		       0x7608

#define GEN7_SF_CTL		       0x7b00
#define GEN7_SF_CTL_SNAPSHOT_COMPLETE		   (1 << 31)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_0_FF_ID	   (0 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_0_REL_COUNT (1 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_1_FF_ID	   (2 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_1_REL_COUNT (3 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_2_FF_ID	   (4 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_2_REL_COUNT (5 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_VERTEX_COUNT	   (6 << 8)
#define GEN7_SF_CTL_SNAPSHOT_MUX_SF_KERNEL_POINTER  (7 << 8)
#define GEN7_SF_CTL_MIN_MAX_PRIMITIVE_RANGE_ENABLE  (1 << 4)
#define GEN7_SF_CTL_DEBUG_CLIP_RECTANGLE_ENABLE	   (1 << 3)
#define GEN7_SF_CTL_SNAPSHOT_ALL_THREADS		   (1 << 2)
#define GEN7_SF_CTL_THREAD_SNAPSHOT_ENABLE	   (1 << 1)
#define GEN7_SF_CTL_SNAPSHOT_ENABLE		   (1 << 0)

#define GEN7_SF_STRG_VAL		       0x7b04
#define GEN7_SF_RDATA		       0x7b18

#define GEN7_WIZ_CTL		       0x7c00
#define GEN7_WIZ_CTL_SNAPSHOT_COMPLETE		   (1 << 31)
#define GEN7_WIZ_CTL_SUBSPAN_INSTANCE_SHIFT	   16
#define GEN7_WIZ_CTL_SNAPSHOT_MUX_WIZ_KERNEL_POINTER   (0 << 8)
#define GEN7_WIZ_CTL_SNAPSHOT_MUX_SUBSPAN_INSTANCE     (1 << 8)
#define GEN7_WIZ_CTL_SNAPSHOT_MUX_PRIMITIVE_SEQUENCE   (2 << 8)
#define GEN7_WIZ_CTL_SINGLE_SUBSPAN_DISPATCH	      (1 << 6)
#define GEN7_WIZ_CTL_IGNORE_COLOR_SCOREBOARD_STALLS    (1 << 5)
#define GEN7_WIZ_CTL_ENABLE_SUBSPAN_INSTANCE_COMPARE   (1 << 4)
#define GEN7_WIZ_CTL_USE_UPSTREAM_SNAPSHOT_FLAG	      (1 << 3)
#define GEN7_WIZ_CTL_SNAPSHOT_ALL_THREADS	      (1 << 2)
#define GEN7_WIZ_CTL_THREAD_SNAPSHOT_ENABLE	      (1 << 1)
#define GEN7_WIZ_CTL_SNAPSHOT_ENABLE		      (1 << 0)

#define GEN7_WIZ_STRG_VAL			      0x7c04
#define GEN7_WIZ_RDATA				      0x7c18

#define GEN7_TS_CTL		       0x7e00
#define GEN7_TS_CTL_SNAPSHOT_COMPLETE		   (1 << 31)
#define GEN7_TS_CTL_SNAPSHOT_MESSAGE_ERROR	   (0 << 8)
#define GEN7_TS_CTL_SNAPSHOT_INTERFACE_DESCRIPTOR   (3 << 8)
#define GEN7_TS_CTL_SNAPSHOT_ALL_CHILD_THREADS	   (1 << 2)
#define GEN7_TS_CTL_SNAPSHOT_ALL_ROOT_THREADS	   (1 << 1)
#define GEN7_TS_CTL_SNAPSHOT_ENABLE		   (1 << 0)

#define GEN7_TS_STRG_VAL		       0x7e04
#define GEN7_TS_RDATA		       0x7e08

#define GEN7_TD_CTL		       0x8000
#define GEN7_TD_CTL_MUX_SHIFT	       8
#define GEN7_TD_CTL_EXTERNAL_HALT_R0_DEBUG_MATCH	   (1 << 7)
#define GEN7_TD_CTL_FORCE_EXTERNAL_HALT		   (1 << 6)
#define GEN7_TD_CTL_EXCEPTION_MASK_OVERRIDE	   (1 << 5)
#define GEN7_TD_CTL_FORCE_THREAD_BREAKPOINT_ENABLE  (1 << 4)
#define GEN7_TD_CTL_BREAKPOINT_ENABLE		   (1 << 2)
#define GEN7_TD_CTL2		       0x8004
#define GEN7_TD_CTL2_ILLEGAL_OPCODE_EXCEPTION_OVERRIDE (1 << 28)
#define GEN7_TD_CTL2_MASKSTACK_EXCEPTION_OVERRIDE      (1 << 26)
#define GEN7_TD_CTL2_SOFTWARE_EXCEPTION_OVERRIDE	      (1 << 25)
#define GEN7_TD_CTL2_ACTIVE_THREAD_LIMIT_SHIFT	      16
#define GEN7_TD_CTL2_ACTIVE_THREAD_LIMIT_ENABLE	      (1 << 8)
#define GEN7_TD_CTL2_THREAD_SPAWNER_EXECUTION_MASK_ENABLE (1 << 7)
#define GEN7_TD_CTL2_WIZ_EXECUTION_MASK_ENABLE	      (1 << 6)
#define GEN7_TD_CTL2_SF_EXECUTION_MASK_ENABLE	      (1 << 5)
#define GEN7_TD_CTL2_CLIPPER_EXECUTION_MASK_ENABLE     (1 << 4)
#define GEN7_TD_CTL2_GS_EXECUTION_MASK_ENABLE	      (1 << 3)
#define GEN7_TD_CTL2_VS_EXECUTION_MASK_ENABLE	      (1 << 0)
#define GEN7_TD_VF_VS_EMSK	       0x8008
#define GEN7_TD_GS_EMSK		       0x800c
#define GEN7_TD_CLIP_EMSK	       0x8010
#define GEN7_TD_SF_EMSK		       0x8014
#define GEN7_TD_WIZ_EMSK		       0x8018
#define GEN7_TD_0_6_EHTRG_VAL	       0x801c
#define GEN7_TD_0_7_EHTRG_VAL	       0x8020
#define GEN7_TD_0_6_EHTRG_MSK           0x8024
#define GEN7_TD_0_7_EHTRG_MSK	       0x8028
#define GEN7_TD_RDATA		       0x802c
#define GEN7_TD_TS_EMSK		       0x8030

#define GEN7_EU_CTL		       0x8800
#define GEN7_EU_CTL_SELECT_SHIFT	       16
#define GEN7_EU_CTL_DATA_MUX_SHIFT      8
#define GEN7_EU_ATT_0		       0x8810
#define GEN7_EU_ATT_1		       0x8814
#define GEN7_EU_ATT_DATA_0	       0x8820
#define GEN7_EU_ATT_DATA_1	       0x8824
#define GEN7_EU_ATT_CLR_0	       0x8830
#define GEN7_EU_ATT_CLR_1	       0x8834
#define GEN7_EU_RDATA		       0x8840

#define _3DPRIM_POINTLIST         0x01
#define _3DPRIM_LINELIST          0x02
#define _3DPRIM_LINESTRIP         0x03
#define _3DPRIM_TRILIST           0x04
#define _3DPRIM_TRISTRIP          0x05
#define _3DPRIM_TRIFAN            0x06
#define _3DPRIM_QUADLIST          0x07
#define _3DPRIM_QUADSTRIP         0x08
#define _3DPRIM_LINELIST_ADJ      0x09
#define _3DPRIM_LINESTRIP_ADJ     0x0A
#define _3DPRIM_TRILIST_ADJ       0x0B
#define _3DPRIM_TRISTRIP_ADJ      0x0C
#define _3DPRIM_TRISTRIP_REVERSE  0x0D
#define _3DPRIM_POLYGON           0x0E
#define _3DPRIM_RECTLIST          0x0F
#define _3DPRIM_LINELOOP          0x10
#define _3DPRIM_POINTLIST_BF      0x11
#define _3DPRIM_LINESTRIP_CONT    0x12
#define _3DPRIM_LINESTRIP_BF      0x13
#define _3DPRIM_LINESTRIP_CONT_BF 0x14
#define _3DPRIM_TRIFAN_NOSTIPPLE  0x15

#define _3DPRIM_VERTEXBUFFER_ACCESS_SEQUENTIAL 0
#define _3DPRIM_VERTEXBUFFER_ACCESS_RANDOM     1

#define GEN7_ANISORATIO_2     0
#define GEN7_ANISORATIO_4     1
#define GEN7_ANISORATIO_6     2
#define GEN7_ANISORATIO_8     3
#define GEN7_ANISORATIO_10    4
#define GEN7_ANISORATIO_12    5
#define GEN7_ANISORATIO_14    6
#define GEN7_ANISORATIO_16    7

#define GEN7_BLENDFACTOR_ONE                 0x1
#define GEN7_BLENDFACTOR_SRC_COLOR           0x2
#define GEN7_BLENDFACTOR_SRC_ALPHA           0x3
#define GEN7_BLENDFACTOR_DST_ALPHA           0x4
#define GEN7_BLENDFACTOR_DST_COLOR           0x5
#define GEN7_BLENDFACTOR_SRC_ALPHA_SATURATE  0x6
#define GEN7_BLENDFACTOR_CONST_COLOR         0x7
#define GEN7_BLENDFACTOR_CONST_ALPHA         0x8
#define GEN7_BLENDFACTOR_SRC1_COLOR          0x9
#define GEN7_BLENDFACTOR_SRC1_ALPHA          0x0A
#define GEN7_BLENDFACTOR_ZERO                0x11
#define GEN7_BLENDFACTOR_INV_SRC_COLOR       0x12
#define GEN7_BLENDFACTOR_INV_SRC_ALPHA       0x13
#define GEN7_BLENDFACTOR_INV_DST_ALPHA       0x14
#define GEN7_BLENDFACTOR_INV_DST_COLOR       0x15
#define GEN7_BLENDFACTOR_INV_CONST_COLOR     0x17
#define GEN7_BLENDFACTOR_INV_CONST_ALPHA     0x18
#define GEN7_BLENDFACTOR_INV_SRC1_COLOR      0x19
#define GEN7_BLENDFACTOR_INV_SRC1_ALPHA      0x1A

#define GEN7_BLENDFUNCTION_ADD               0
#define GEN7_BLENDFUNCTION_SUBTRACT          1
#define GEN7_BLENDFUNCTION_REVERSE_SUBTRACT  2
#define GEN7_BLENDFUNCTION_MIN               3
#define GEN7_BLENDFUNCTION_MAX               4

#define GEN7_ALPHATEST_FORMAT_UNORM8         0
#define GEN7_ALPHATEST_FORMAT_FLOAT32        1

#define GEN7_CHROMAKEY_KILL_ON_ANY_MATCH  0
#define GEN7_CHROMAKEY_REPLACE_BLACK      1

#define GEN7_CLIP_API_OGL     0
#define GEN7_CLIP_API_DX      1

#define GEN7_CLIPMODE_NORMAL              0
#define GEN7_CLIPMODE_CLIP_ALL            1
#define GEN7_CLIPMODE_CLIP_NON_REJECTED   2
#define GEN7_CLIPMODE_REJECT_ALL          3
#define GEN7_CLIPMODE_ACCEPT_ALL          4

#define GEN7_CLIP_NDCSPACE     0
#define GEN7_CLIP_SCREENSPACE  1

#define GEN7_COMPAREFUNCTION_ALWAYS       0
#define GEN7_COMPAREFUNCTION_NEVER        1
#define GEN7_COMPAREFUNCTION_LESS         2
#define GEN7_COMPAREFUNCTION_EQUAL        3
#define GEN7_COMPAREFUNCTION_LEQUAL       4
#define GEN7_COMPAREFUNCTION_GREATER      5
#define GEN7_COMPAREFUNCTION_NOTEQUAL     6
#define GEN7_COMPAREFUNCTION_GEQUAL       7

#define GEN7_COVERAGE_PIXELS_HALF     0
#define GEN7_COVERAGE_PIXELS_1        1
#define GEN7_COVERAGE_PIXELS_2        2
#define GEN7_COVERAGE_PIXELS_4        3

#define GEN7_CULLMODE_BOTH        0
#define GEN7_CULLMODE_NONE        1
#define GEN7_CULLMODE_FRONT       2
#define GEN7_CULLMODE_BACK        3

#define GEN7_DEFAULTCOLOR_R8G8B8A8_UNORM      0
#define GEN7_DEFAULTCOLOR_R32G32B32A32_FLOAT  1

#define GEN7_DEPTHFORMAT_D32_FLOAT_S8X24_UINT     0
#define GEN7_DEPTHFORMAT_D32_FLOAT                1
#define GEN7_DEPTHFORMAT_D24_UNORM_S8_UINT        2
#define GEN7_DEPTHFORMAT_D16_UNORM                5

#define GEN7_FLOATING_POINT_IEEE_754        0
#define GEN7_FLOATING_POINT_NON_IEEE_754    1

#define GEN7_FRONTWINDING_CW      0
#define GEN7_FRONTWINDING_CCW     1

#define GEN7_INDEX_BYTE     0
#define GEN7_INDEX_WORD     1
#define GEN7_INDEX_DWORD    2

#define GEN7_LOGICOPFUNCTION_CLEAR            0
#define GEN7_LOGICOPFUNCTION_NOR              1
#define GEN7_LOGICOPFUNCTION_AND_INVERTED     2
#define GEN7_LOGICOPFUNCTION_COPY_INVERTED    3
#define GEN7_LOGICOPFUNCTION_AND_REVERSE      4
#define GEN7_LOGICOPFUNCTION_INVERT           5
#define GEN7_LOGICOPFUNCTION_XOR              6
#define GEN7_LOGICOPFUNCTION_NAND             7
#define GEN7_LOGICOPFUNCTION_AND              8
#define GEN7_LOGICOPFUNCTION_EQUIV            9
#define GEN7_LOGICOPFUNCTION_NOOP             10
#define GEN7_LOGICOPFUNCTION_OR_INVERTED      11
#define GEN7_LOGICOPFUNCTION_COPY             12
#define GEN7_LOGICOPFUNCTION_OR_REVERSE       13
#define GEN7_LOGICOPFUNCTION_OR               14
#define GEN7_LOGICOPFUNCTION_SET              15

#define GEN7_MAPFILTER_NEAREST        0x0
#define GEN7_MAPFILTER_LINEAR         0x1
#define GEN7_MAPFILTER_ANISOTROPIC    0x2

#define GEN7_MIPFILTER_NONE        0
#define GEN7_MIPFILTER_NEAREST     1
#define GEN7_MIPFILTER_LINEAR      3

#define GEN7_POLYGON_FRONT_FACING     0
#define GEN7_POLYGON_BACK_FACING      1

#define GEN7_PREFILTER_ALWAYS     0x0
#define GEN7_PREFILTER_NEVER      0x1
#define GEN7_PREFILTER_LESS       0x2
#define GEN7_PREFILTER_EQUAL      0x3
#define GEN7_PREFILTER_LEQUAL     0x4
#define GEN7_PREFILTER_GREATER    0x5
#define GEN7_PREFILTER_NOTEQUAL   0x6
#define GEN7_PREFILTER_GEQUAL     0x7

#define GEN7_PROVOKING_VERTEX_0    0
#define GEN7_PROVOKING_VERTEX_1    1
#define GEN7_PROVOKING_VERTEX_2    2

#define GEN7_RASTRULE_UPPER_LEFT  0
#define GEN7_RASTRULE_UPPER_RIGHT 1

#define GEN7_RENDERTARGET_CLAMPRANGE_UNORM    0
#define GEN7_RENDERTARGET_CLAMPRANGE_SNORM    1
#define GEN7_RENDERTARGET_CLAMPRANGE_FORMAT   2

#define GEN7_STENCILOP_KEEP               0
#define GEN7_STENCILOP_ZERO               1
#define GEN7_STENCILOP_REPLACE            2
#define GEN7_STENCILOP_INCRSAT            3
#define GEN7_STENCILOP_DECRSAT            4
#define GEN7_STENCILOP_INCR               5
#define GEN7_STENCILOP_DECR               6
#define GEN7_STENCILOP_INVERT             7

#define GEN7_BORDER_COLOR_MODE_DEFAULT	0
#define GEN7_BORDER_COLOR_MODE_LEGACY	1

#define GEN7_TEXCOORDMODE_WRAP            0
#define GEN7_TEXCOORDMODE_MIRROR          1
#define GEN7_TEXCOORDMODE_CLAMP           2
#define GEN7_TEXCOORDMODE_CUBE            3
#define GEN7_TEXCOORDMODE_CLAMP_BORDER    4
#define GEN7_TEXCOORDMODE_MIRROR_ONCE     5

#define GEN7_THREAD_PRIORITY_NORMAL   0
#define GEN7_THREAD_PRIORITY_HIGH     1

#define GEN7_TILEWALK_XMAJOR                 0
#define GEN7_TILEWALK_YMAJOR                 1

#define GEN7_VERTEX_SUBPIXEL_PRECISION_8BITS  0
#define GEN7_VERTEX_SUBPIXEL_PRECISION_4BITS  1

#define GEN7_VERTEXBUFFER_ACCESS_VERTEXDATA     0
#define GEN7_VERTEXBUFFER_ACCESS_INSTANCEDATA   1

#define GEN7_VFCOMPONENT_NOSTORE      0
#define GEN7_VFCOMPONENT_STORE_SRC    1
#define GEN7_VFCOMPONENT_STORE_0      2
#define GEN7_VFCOMPONENT_STORE_1_FLT  3
#define GEN7_VFCOMPONENT_STORE_1_INT  4
#define GEN7_VFCOMPONENT_STORE_VID    5
#define GEN7_VFCOMPONENT_STORE_IID    6
#define GEN7_VFCOMPONENT_STORE_PID    7


/* Execution Unit (EU) defines
 */

#define GEN7_ALIGN_1   0
#define GEN7_ALIGN_16  1

#define GEN7_ADDRESS_DIRECT                        0
#define GEN7_ADDRESS_REGISTER_INDIRECT_REGISTER    1

#define GEN7_CHANNEL_X     0
#define GEN7_CHANNEL_Y     1
#define GEN7_CHANNEL_Z     2
#define GEN7_CHANNEL_W     3

#define GEN7_COMPRESSION_NONE          0
#define GEN7_COMPRESSION_2NDHALF       1
#define GEN7_COMPRESSION_COMPRESSED    2

#define GEN7_CONDITIONAL_NONE  0
#define GEN7_CONDITIONAL_Z     1
#define GEN7_CONDITIONAL_NZ    2
#define GEN7_CONDITIONAL_EQ    1	/* Z */
#define GEN7_CONDITIONAL_NEQ   2	/* NZ */
#define GEN7_CONDITIONAL_G     3
#define GEN7_CONDITIONAL_GE    4
#define GEN7_CONDITIONAL_L     5
#define GEN7_CONDITIONAL_LE    6
#define GEN7_CONDITIONAL_C     7
#define GEN7_CONDITIONAL_O     8

#define GEN7_DEBUG_NONE        0
#define GEN7_DEBUG_BREAKPOINT  1

#define GEN7_DEPENDENCY_NORMAL         0
#define GEN7_DEPENDENCY_NOTCLEARED     1
#define GEN7_DEPENDENCY_NOTCHECKED     2
#define GEN7_DEPENDENCY_DISABLE        3

#define GEN7_EXECUTE_1     0
#define GEN7_EXECUTE_2     1
#define GEN7_EXECUTE_4     2
#define GEN7_EXECUTE_8     3
#define GEN7_EXECUTE_16    4
#define GEN7_EXECUTE_32    5

#define GEN7_HORIZONTAL_STRIDE_0   0
#define GEN7_HORIZONTAL_STRIDE_1   1
#define GEN7_HORIZONTAL_STRIDE_2   2
#define GEN7_HORIZONTAL_STRIDE_4   3

#define GEN7_INSTRUCTION_NORMAL    0
#define GEN7_INSTRUCTION_SATURATE  1

#define INTEL_MASK_ENABLE   0
#define INTEL_MASK_DISABLE  1

#define GEN7_OPCODE_MOV        1
#define GEN7_OPCODE_SEL        2
#define GEN7_OPCODE_NOT        4
#define GEN7_OPCODE_AND        5
#define GEN7_OPCODE_OR         6
#define GEN7_OPCODE_XOR        7
#define GEN7_OPCODE_SHR        8
#define GEN7_OPCODE_SHL        9
#define GEN7_OPCODE_RSR        10
#define GEN7_OPCODE_RSL        11
#define GEN7_OPCODE_ASR        12
#define GEN7_OPCODE_CMP        16
#define GEN7_OPCODE_JMPI       32
#define GEN7_OPCODE_IF         34
#define GEN7_OPCODE_IFF        35
#define GEN7_OPCODE_ELSE       36
#define GEN7_OPCODE_ENDIF      37
#define GEN7_OPCODE_DO         38
#define GEN7_OPCODE_WHILE      39
#define GEN7_OPCODE_BREAK      40
#define GEN7_OPCODE_CONTINUE   41
#define GEN7_OPCODE_HALT       42
#define GEN7_OPCODE_MSAVE      44
#define GEN7_OPCODE_MRESTORE   45
#define GEN7_OPCODE_PUSH       46
#define GEN7_OPCODE_POP        47
#define GEN7_OPCODE_WAIT       48
#define GEN7_OPCODE_SEND       49
#define GEN7_OPCODE_ADD        64
#define GEN7_OPCODE_MUL        65
#define GEN7_OPCODE_AVG        66
#define GEN7_OPCODE_FRC        67
#define GEN7_OPCODE_RNDU       68
#define GEN7_OPCODE_RNDD       69
#define GEN7_OPCODE_RNDE       70
#define GEN7_OPCODE_RNDZ       71
#define GEN7_OPCODE_MAC        72
#define GEN7_OPCODE_MACH       73
#define GEN7_OPCODE_LZD        74
#define GEN7_OPCODE_SAD2       80
#define GEN7_OPCODE_SADA2      81
#define GEN7_OPCODE_DP4        84
#define GEN7_OPCODE_DPH        85
#define GEN7_OPCODE_DP3        86
#define GEN7_OPCODE_DP2        87
#define GEN7_OPCODE_DPA2       88
#define GEN7_OPCODE_LINE       89
#define GEN7_OPCODE_NOP        126

#define GEN7_PREDICATE_NONE             0
#define GEN7_PREDICATE_NORMAL           1
#define GEN7_PREDICATE_ALIGN1_ANYV             2
#define GEN7_PREDICATE_ALIGN1_ALLV             3
#define GEN7_PREDICATE_ALIGN1_ANY2H            4
#define GEN7_PREDICATE_ALIGN1_ALL2H            5
#define GEN7_PREDICATE_ALIGN1_ANY4H            6
#define GEN7_PREDICATE_ALIGN1_ALL4H            7
#define GEN7_PREDICATE_ALIGN1_ANY8H            8
#define GEN7_PREDICATE_ALIGN1_ALL8H            9
#define GEN7_PREDICATE_ALIGN1_ANY16H           10
#define GEN7_PREDICATE_ALIGN1_ALL16H           11
#define GEN7_PREDICATE_ALIGN16_REPLICATE_X     2
#define GEN7_PREDICATE_ALIGN16_REPLICATE_Y     3
#define GEN7_PREDICATE_ALIGN16_REPLICATE_Z     4
#define GEN7_PREDICATE_ALIGN16_REPLICATE_W     5
#define GEN7_PREDICATE_ALIGN16_ANY4H           6
#define GEN7_PREDICATE_ALIGN16_ALL4H           7

#define GEN7_ARCHITECTURE_REGISTER_FILE    0
#define GEN7_GENERAL_REGISTER_FILE         1
#define GEN7_MESSAGE_REGISTER_FILE         2
#define GEN7_IMMEDIATE_VALUE               3

#define GEN7_REGISTER_TYPE_UD  0
#define GEN7_REGISTER_TYPE_D   1
#define GEN7_REGISTER_TYPE_UW  2
#define GEN7_REGISTER_TYPE_W   3
#define GEN7_REGISTER_TYPE_UB  4
#define GEN7_REGISTER_TYPE_B   5
#define GEN7_REGISTER_TYPE_VF  5	/* packed float vector, immediates only? */
#define GEN7_REGISTER_TYPE_HF  6
#define GEN7_REGISTER_TYPE_V   6	/* packed int vector, immediates only, uword dest only */
#define GEN7_REGISTER_TYPE_F   7

#define GEN7_ARF_NULL                  0x00
#define GEN7_ARF_ADDRESS               0x10
#define GEN7_ARF_ACCUMULATOR           0x20
#define GEN7_ARF_FLAG                  0x30
#define GEN7_ARF_MASK                  0x40
#define GEN7_ARF_MASK_STACK            0x50
#define GEN7_ARF_MASK_STACK_DEPTH      0x60
#define GEN7_ARF_STATE                 0x70
#define GEN7_ARF_CONTROL               0x80
#define GEN7_ARF_NOTIFICATION_COUNT    0x90
#define GEN7_ARF_IP                    0xA0

#define GEN7_AMASK   0
#define GEN7_IMASK   1
#define GEN7_LMASK   2
#define GEN7_CMASK   3

#define GEN7_THREAD_NORMAL     0
#define GEN7_THREAD_ATOMIC     1
#define GEN7_THREAD_SWITCH     2

#define GEN7_VERTICAL_STRIDE_0                 0
#define GEN7_VERTICAL_STRIDE_1                 1
#define GEN7_VERTICAL_STRIDE_2                 2
#define GEN7_VERTICAL_STRIDE_4                 3
#define GEN7_VERTICAL_STRIDE_8                 4
#define GEN7_VERTICAL_STRIDE_16                5
#define GEN7_VERTICAL_STRIDE_32                6
#define GEN7_VERTICAL_STRIDE_64                7
#define GEN7_VERTICAL_STRIDE_128               8
#define GEN7_VERTICAL_STRIDE_256               9
#define GEN7_VERTICAL_STRIDE_ONE_DIMENSIONAL   0xF

#define GEN7_WIDTH_1       0
#define GEN7_WIDTH_2       1
#define GEN7_WIDTH_4       2
#define GEN7_WIDTH_8       3
#define GEN7_WIDTH_16      4

#define GEN7_STATELESS_BUFFER_BOUNDARY_1K      0
#define GEN7_STATELESS_BUFFER_BOUNDARY_2K      1
#define GEN7_STATELESS_BUFFER_BOUNDARY_4K      2
#define GEN7_STATELESS_BUFFER_BOUNDARY_8K      3
#define GEN7_STATELESS_BUFFER_BOUNDARY_16K     4
#define GEN7_STATELESS_BUFFER_BOUNDARY_32K     5
#define GEN7_STATELESS_BUFFER_BOUNDARY_64K     6
#define GEN7_STATELESS_BUFFER_BOUNDARY_128K    7
#define GEN7_STATELESS_BUFFER_BOUNDARY_256K    8
#define GEN7_STATELESS_BUFFER_BOUNDARY_512K    9
#define GEN7_STATELESS_BUFFER_BOUNDARY_1M      10
#define GEN7_STATELESS_BUFFER_BOUNDARY_2M      11

#define GEN7_POLYGON_FACING_FRONT      0
#define GEN7_POLYGON_FACING_BACK       1

#define GEN7_MESSAGE_TARGET_NULL               0
#define GEN7_MESSAGE_TARGET_MATH               1
#define GEN7_MESSAGE_TARGET_SAMPLER            2
#define GEN7_MESSAGE_TARGET_GATEWAY            3
#define GEN7_MESSAGE_TARGET_DATAPORT_READ      4
#define GEN7_MESSAGE_TARGET_DATAPORT_WRITE     5
#define GEN7_MESSAGE_TARGET_URB                6
#define GEN7_MESSAGE_TARGET_THREAD_SPAWNER     7

#define GEN7_SAMPLER_RETURN_FORMAT_FLOAT32     0
#define GEN7_SAMPLER_RETURN_FORMAT_UINT32      2
#define GEN7_SAMPLER_RETURN_FORMAT_SINT32      3

#define GEN7_SAMPLER_MESSAGE_SIMD8_SAMPLE              0
#define GEN7_SAMPLER_MESSAGE_SIMD16_SAMPLE             0
#define GEN7_SAMPLER_MESSAGE_SIMD16_SAMPLE_BIAS        0
#define GEN7_SAMPLER_MESSAGE_SIMD8_KILLPIX             1
#define GEN7_SAMPLER_MESSAGE_SIMD4X2_SAMPLE_LOD        1
#define GEN7_SAMPLER_MESSAGE_SIMD16_SAMPLE_LOD         1
#define GEN7_SAMPLER_MESSAGE_SIMD4X2_SAMPLE_GRADIENTS  2
#define GEN7_SAMPLER_MESSAGE_SIMD8_SAMPLE_GRADIENTS    2
#define GEN7_SAMPLER_MESSAGE_SIMD4X2_SAMPLE_COMPARE    0
#define GEN7_SAMPLER_MESSAGE_SIMD16_SAMPLE_COMPARE     2
#define GEN7_SAMPLER_MESSAGE_SIMD4X2_RESINFO           2
#define GEN7_SAMPLER_MESSAGE_SIMD8_RESINFO             2
#define GEN7_SAMPLER_MESSAGE_SIMD16_RESINFO            2
#define GEN7_SAMPLER_MESSAGE_SIMD4X2_LD                3
#define GEN7_SAMPLER_MESSAGE_SIMD8_LD                  3
#define GEN7_SAMPLER_MESSAGE_SIMD16_LD                 3

#define GEN7_DATAPORT_OWORD_BLOCK_1_OWORDLOW   0
#define GEN7_DATAPORT_OWORD_BLOCK_1_OWORDHIGH  1
#define GEN7_DATAPORT_OWORD_BLOCK_2_OWORDS     2
#define GEN7_DATAPORT_OWORD_BLOCK_4_OWORDS     3
#define GEN7_DATAPORT_OWORD_BLOCK_8_OWORDS     4

#define GEN7_DATAPORT_OWORD_DUAL_BLOCK_1OWORD     0
#define GEN7_DATAPORT_OWORD_DUAL_BLOCK_4OWORDS    2

#define GEN7_DATAPORT_DWORD_SCATTERED_BLOCK_8DWORDS   2
#define GEN7_DATAPORT_DWORD_SCATTERED_BLOCK_16DWORDS  3

#define GEN7_DATAPORT_READ_MESSAGE_OWORD_BLOCK_READ          0
#define GEN7_DATAPORT_READ_MESSAGE_OWORD_DUAL_BLOCK_READ     1
#define GEN7_DATAPORT_READ_MESSAGE_DWORD_BLOCK_READ          2
#define GEN7_DATAPORT_READ_MESSAGE_DWORD_SCATTERED_READ      3

#define GEN7_DATAPORT_READ_TARGET_DATA_CACHE      0
#define GEN7_DATAPORT_READ_TARGET_RENDER_CACHE    1
#define GEN7_DATAPORT_READ_TARGET_SAMPLER_CACHE   2

#define GEN7_DATAPORT_RENDER_TARGET_WRITE_SIMD16_SINGLE_SOURCE                0
#define GEN7_DATAPORT_RENDER_TARGET_WRITE_SIMD16_SINGLE_SOURCE_REPLICATED     1
#define GEN7_DATAPORT_RENDER_TARGET_WRITE_SIMD8_DUAL_SOURCE_SUBSPAN01         2
#define GEN7_DATAPORT_RENDER_TARGET_WRITE_SIMD8_DUAL_SOURCE_SUBSPAN23         3
#define GEN7_DATAPORT_RENDER_TARGET_WRITE_SIMD8_SINGLE_SOURCE_SUBSPAN01       4

#define GEN7_DATAPORT_WRITE_MESSAGE_OWORD_BLOCK_WRITE                0
#define GEN7_DATAPORT_WRITE_MESSAGE_OWORD_DUAL_BLOCK_WRITE           1
#define GEN7_DATAPORT_WRITE_MESSAGE_DWORD_BLOCK_WRITE                2
#define GEN7_DATAPORT_WRITE_MESSAGE_DWORD_SCATTERED_WRITE            3
#define GEN7_DATAPORT_WRITE_MESSAGE_RENDER_TARGET_WRITE              4
#define GEN7_DATAPORT_WRITE_MESSAGE_STREAMED_VERTEX_BUFFER_WRITE     5
#define GEN7_DATAPORT_WRITE_MESSAGE_FLUSH_RENDER_CACHE               7

#define GEN7_MATH_FUNCTION_INV                              1
#define GEN7_MATH_FUNCTION_LOG                              2
#define GEN7_MATH_FUNCTION_EXP                              3
#define GEN7_MATH_FUNCTION_SQRT                             4
#define GEN7_MATH_FUNCTION_RSQ                              5
#define GEN7_MATH_FUNCTION_SIN                              6 /* was 7 */
#define GEN7_MATH_FUNCTION_COS                              7 /* was 8 */
#define GEN7_MATH_FUNCTION_SINCOS                           8 /* was 6 */
#define GEN7_MATH_FUNCTION_TAN                              9
#define GEN7_MATH_FUNCTION_POW                              10
#define GEN7_MATH_FUNCTION_INT_DIV_QUOTIENT_AND_REMAINDER   11
#define GEN7_MATH_FUNCTION_INT_DIV_QUOTIENT                 12
#define GEN7_MATH_FUNCTION_INT_DIV_REMAINDER                13

#define GEN7_MATH_INTEGER_UNSIGNED     0
#define GEN7_MATH_INTEGER_SIGNED       1

#define GEN7_MATH_PRECISION_FULL        0
#define GEN7_MATH_PRECISION_PARTIAL     1

#define GEN7_MATH_SATURATE_NONE         0
#define GEN7_MATH_SATURATE_SATURATE     1

#define GEN7_MATH_DATA_VECTOR  0
#define GEN7_MATH_DATA_SCALAR  1

#define GEN7_URB_OPCODE_WRITE  0

#define GEN7_URB_SWIZZLE_NONE          0
#define GEN7_URB_SWIZZLE_INTERLEAVE    1
#define GEN7_URB_SWIZZLE_TRANSPOSE     2

#define GEN7_SCRATCH_SPACE_SIZE_1K     0
#define GEN7_SCRATCH_SPACE_SIZE_2K     1
#define GEN7_SCRATCH_SPACE_SIZE_4K     2
#define GEN7_SCRATCH_SPACE_SIZE_8K     3
#define GEN7_SCRATCH_SPACE_SIZE_16K    4
#define GEN7_SCRATCH_SPACE_SIZE_32K    5
#define GEN7_SCRATCH_SPACE_SIZE_64K    6
#define GEN7_SCRATCH_SPACE_SIZE_128K   7
#define GEN7_SCRATCH_SPACE_SIZE_256K   8
#define GEN7_SCRATCH_SPACE_SIZE_512K   9
#define GEN7_SCRATCH_SPACE_SIZE_1M     10
#define GEN7_SCRATCH_SPACE_SIZE_2M     11

/* The hardware supports two different modes for border color. The
 * default (OpenGL) mode uses floating-point color channels, while the
 * legacy mode uses 4 bytes.
 *
 * More significantly, the legacy mode respects the components of the
 * border color for channels not present in the source, (whereas the
 * default mode will ignore the border color's alpha channel and use
 * alpha==1 for an RGB source, for example).
 *
 * The legacy mode matches the semantics specified by the Render
 * extension.
 */
struct gen7_sampler_default_border_color {
   float color[4];
};

struct gen7_sampler_legacy_border_color {
   uint8_t color[4];
};

struct gen7_blend_state {
	struct {
		uint32_t dest_blend_factor:5;
		uint32_t source_blend_factor:5;
		uint32_t pad3:1;
		uint32_t blend_func:3;
		uint32_t pad2:1;
		uint32_t ia_dest_blend_factor:5;
		uint32_t ia_source_blend_factor:5;
		uint32_t pad1:1;
		uint32_t ia_blend_func:3;
		uint32_t pad0:1;
		uint32_t ia_blend_enable:1;
		uint32_t blend_enable:1;
	} blend0;

	struct {
		uint32_t post_blend_clamp_enable:1;
		uint32_t pre_blend_clamp_enable:1;
		uint32_t clamp_range:2;
		uint32_t pad0:4;
		uint32_t x_dither_offset:2;
		uint32_t y_dither_offset:2;
		uint32_t dither_enable:1;
		uint32_t alpha_test_func:3;
		uint32_t alpha_test_enable:1;
		uint32_t pad1:1;
		uint32_t logic_op_func:4;
		uint32_t logic_op_enable:1;
		uint32_t pad2:1;
		uint32_t write_disable_b:1;
		uint32_t write_disable_g:1;
		uint32_t write_disable_r:1;
		uint32_t write_disable_a:1;
		uint32_t pad3:1;
		uint32_t alpha_to_coverage_dither:1;
		uint32_t alpha_to_one:1;
		uint32_t alpha_to_coverage:1;
	} blend1;
};

struct gen7_color_calc_state {
	struct {
		uint32_t alpha_test_format:1;
		uint32_t pad0:14;
		uint32_t round_disable:1;
		uint32_t bf_stencil_ref:8;
		uint32_t stencil_ref:8;
	} cc0;

	union {
		float alpha_ref_f;
		struct {
			uint32_t ui:8;
			uint32_t pad0:24;
		} alpha_ref_fi;
	} cc1;

	float constant_r;
	float constant_g;
	float constant_b;
	float constant_a;
};

struct gen7_depth_stencil_state {
	struct {
		uint32_t pad0:3;
		uint32_t bf_stencil_pass_depth_pass_op:3;
		uint32_t bf_stencil_pass_depth_fail_op:3;
		uint32_t bf_stencil_fail_op:3;
		uint32_t bf_stencil_func:3;
		uint32_t bf_stencil_enable:1;
		uint32_t pad1:2;
		uint32_t stencil_write_enable:1;
		uint32_t stencil_pass_depth_pass_op:3;
		uint32_t stencil_pass_depth_fail_op:3;
		uint32_t stencil_fail_op:3;
		uint32_t stencil_func:3;
		uint32_t stencil_enable:1;
	} ds0;

	struct {
		uint32_t bf_stencil_write_mask:8;
		uint32_t bf_stencil_test_mask:8;
		uint32_t stencil_write_mask:8;
		uint32_t stencil_test_mask:8;
	} ds1;

	struct {
		uint32_t pad0:26;
		uint32_t depth_write_enable:1;
		uint32_t depth_test_func:3;
		uint32_t pad1:1;
		uint32_t depth_test_enable:1;
	} ds2;
};

struct gen7_surface_state {
	struct {
		unsigned int cube_pos_z:1;
		unsigned int cube_neg_z:1;
		unsigned int cube_pos_y:1;
		unsigned int cube_neg_y:1;
		unsigned int cube_pos_x:1;
		unsigned int cube_neg_x:1;
		unsigned int pad2:2;
		unsigned int render_cache_read_write:1;
		unsigned int pad1:1;
		unsigned int surface_array_spacing:1;
		unsigned int vert_line_stride_ofs:1;
		unsigned int vert_line_stride:1;
		unsigned int tile_walk:1;
		unsigned int tiled_surface:1;
		unsigned int horizontal_alignment:1;
		unsigned int vertical_alignment:2;
		unsigned int surface_format:9;     /**< BRW_SURFACEFORMAT_x */
		unsigned int pad0:1;
		unsigned int is_array:1;
		unsigned int surface_type:3;       /**< BRW_SURFACE_1D/2D/3D/CUBE */
	} ss0;

	struct {
		unsigned int base_addr;
	} ss1;

	struct {
		unsigned int width:14;
		unsigned int pad1:2;
		unsigned int height:14;
		unsigned int pad0:2;
	} ss2;

	struct {
		unsigned int pitch:18;
		unsigned int pad:3;
		unsigned int depth:11;
	} ss3;

	struct {
		unsigned int multisample_position_palette_index:3;
		unsigned int num_multisamples:3;
		unsigned int multisampled_surface_storage_format:1;
		unsigned int render_target_view_extent:11;
		unsigned int min_array_elt:11;
		unsigned int rotation:2;
		unsigned int pad0:1;
	} ss4;

	struct {
		unsigned int mip_count:4;
		unsigned int min_lod:4;
		unsigned int pad1:12;
		unsigned int y_offset:4;
		unsigned int pad0:1;
		unsigned int x_offset:7;
	} ss5;

	struct {
		unsigned int pad; /* Multisample Control Surface stuff */
	} ss6;

	struct {
		unsigned int resource_min_lod:12;
		unsigned int pad0:16;
		unsigned int alpha_clear_color:1;
		unsigned int blue_clear_color:1;
		unsigned int green_clear_color:1;
		unsigned int red_clear_color:1;
	} ss7;
};

struct gen7_sampler_state {
	struct {
		unsigned int aniso_algorithm:1;
		unsigned int lod_bias:13;
		unsigned int min_filter:3;
		unsigned int mag_filter:3;
		unsigned int mip_filter:2;
		unsigned int base_level:5;
		unsigned int pad1:1;
		unsigned int lod_preclamp:1;
		unsigned int default_color_mode:1;
		unsigned int pad0:1;
		unsigned int disable:1;
	} ss0;

	struct {
		unsigned int cube_control_mode:1;
		unsigned int shadow_function:3;
		unsigned int pad:4;
		unsigned int max_lod:12;
		unsigned int min_lod:12;
	} ss1;

	struct {
		unsigned int pad:5;
		unsigned int default_color_pointer:27;
	} ss2;

	struct {
		unsigned int r_wrap_mode:3;
		unsigned int t_wrap_mode:3;
		unsigned int s_wrap_mode:3;
		unsigned int pad:1;
		unsigned int non_normalized_coord:1;
		unsigned int trilinear_quality:2;
		unsigned int address_round:6;
		unsigned int max_aniso:3;
		unsigned int chroma_key_mode:1;
		unsigned int chroma_key_index:2;
		unsigned int chroma_key_enable:1;
		unsigned int pad0:6;
	} ss3;
};

/* Surface state DW0 */
#define GEN7_SURFACE_RC_READ_WRITE	(1 << 8)
#define GEN7_SURFACE_TILED		(1 << 14)
#define GEN7_SURFACE_TILED_Y		(1 << 13)
#define GEN7_SURFACE_FORMAT_SHIFT	18
#define GEN7_SURFACE_TYPE_SHIFT		29

/* Surface state DW2 */
#define GEN7_SURFACE_HEIGHT_SHIFT        16
#define GEN7_SURFACE_WIDTH_SHIFT         0

/* Surface state DW3 */
#define GEN7_SURFACE_DEPTH_SHIFT         21
#define GEN7_SURFACE_PITCH_SHIFT         0

#define HSW_SWIZZLE_ZERO		0
#define HSW_SWIZZLE_ONE			1
#define HSW_SWIZZLE_RED			4
#define HSW_SWIZZLE_GREEN		5
#define HSW_SWIZZLE_BLUE		6
#define HSW_SWIZZLE_ALPHA		7
#define __HSW_SURFACE_SWIZZLE(r,g,b,a) \
	((a) << 16 | (b) << 19 | (g) << 22 | (r) << 25)
#define HSW_SURFACE_SWIZZLE(r,g,b,a) \
	__HSW_SURFACE_SWIZZLE(HSW_SWIZZLE_##r, HSW_SWIZZLE_##g, HSW_SWIZZLE_##b, HSW_SWIZZLE_##a)

/* _3DSTATE_VERTEX_BUFFERS on GEN7*/
/* DW1 */
#define GEN7_VB0_ADDRESS_MODIFYENABLE   (1 << 14)

/* _3DPRIMITIVE on GEN7 */
/* DW1 */
# define GEN7_3DPRIM_VERTEXBUFFER_ACCESS_SEQUENTIAL     (0 << 8)
# define GEN7_3DPRIM_VERTEXBUFFER_ACCESS_RANDOM         (1 << 8)

#define GEN7_3DSTATE_CLEAR_PARAMS               GEN7_3D(3, 0, 0x04)
#define GEN7_3DSTATE_DEPTH_BUFFER               GEN7_3D(3, 0, 0x05)
# define GEN7_3DSTATE_DEPTH_BUFFER_TYPE_SHIFT	29
# define GEN7_3DSTATE_DEPTH_BUFFER_FORMAT_SHIFT	18
/* DW1 */
# define GEN7_3DSTATE_DEPTH_CLEAR_VALID		(1 << 15)

#define GEN7_3DSTATE_CONSTANT_HS                GEN7_3D(3, 0, 0x19)
#define GEN7_3DSTATE_CONSTANT_DS                GEN7_3D(3, 0, 0x1a)

#define GEN7_3DSTATE_HS                         GEN7_3D(3, 0, 0x1b)
#define GEN7_3DSTATE_TE                         GEN7_3D(3, 0, 0x1c)
#define GEN7_3DSTATE_DS                         GEN7_3D(3, 0, 0x1d)
#define GEN7_3DSTATE_STREAMOUT                  GEN7_3D(3, 0, 0x1e)
#define GEN7_3DSTATE_SBE                        GEN7_3D(3, 0, 0x1f)

/* DW1 */
# define GEN7_SBE_SWIZZLE_CONTROL_MODE          (1 << 28)
# define GEN7_SBE_NUM_OUTPUTS_SHIFT             22
# define GEN7_SBE_SWIZZLE_ENABLE                (1 << 21)
# define GEN7_SBE_POINT_SPRITE_LOWERLEFT        (1 << 20)
# define GEN7_SBE_URB_ENTRY_READ_LENGTH_SHIFT   11
# define GEN7_SBE_URB_ENTRY_READ_OFFSET_SHIFT   4

#define GEN7_3DSTATE_PS                                 GEN7_3D(3, 0, 0x20)
/* DW1: kernel pointer */
/* DW2 */
# define GEN7_PS_SPF_MODE                               (1 << 31)
# define GEN7_PS_VECTOR_MASK_ENABLE                     (1 << 30)
# define GEN7_PS_SAMPLER_COUNT_SHIFT                    27
# define GEN7_PS_BINDING_TABLE_ENTRY_COUNT_SHIFT        18
# define GEN7_PS_FLOATING_POINT_MODE_IEEE_754           (0 << 16)
# define GEN7_PS_FLOATING_POINT_MODE_ALT                (1 << 16)
/* DW3: scratch space */
/* DW4 */
# define IVB_PS_MAX_THREADS_SHIFT                      24
# define HSW_PS_MAX_THREADS_SHIFT                      23
# define HSW_PS_SAMPLE_MASK_SHIFT                      12
# define GEN7_PS_PUSH_CONSTANT_ENABLE                   (1 << 11)
# define GEN7_PS_ATTRIBUTE_ENABLE                       (1 << 10)
# define GEN7_PS_OMASK_TO_RENDER_TARGET                 (1 << 9)
# define GEN7_PS_DUAL_SOURCE_BLEND_ENABLE               (1 << 7)
# define GEN7_PS_POSOFFSET_NONE                         (0 << 3)
# define GEN7_PS_POSOFFSET_CENTROID                     (2 << 3)
# define GEN7_PS_POSOFFSET_SAMPLE                       (3 << 3)
# define GEN7_PS_32_DISPATCH_ENABLE                     (1 << 2)
# define GEN7_PS_16_DISPATCH_ENABLE                     (1 << 1)
# define GEN7_PS_8_DISPATCH_ENABLE                      (1 << 0)
/* DW5 */
# define GEN7_PS_DISPATCH_START_GRF_SHIFT_0             16
# define GEN7_PS_DISPATCH_START_GRF_SHIFT_1             8
# define GEN7_PS_DISPATCH_START_GRF_SHIFT_2             0
/* DW6: kernel 1 pointer */
/* DW7: kernel 2 pointer */

#define GEN7_3DSTATE_VIEWPORT_STATE_POINTERS_SF_CL      GEN7_3D(3, 0, 0x21)
#define GEN7_3DSTATE_VIEWPORT_STATE_POINTERS_CC         GEN7_3D(3, 0, 0x23)

#define GEN7_3DSTATE_BLEND_STATE_POINTERS               GEN7_3D(3, 0, 0x24)
#define GEN7_3DSTATE_DEPTH_STENCIL_STATE_POINTERS       GEN7_3D(3, 0, 0x25)

#define GEN7_3DSTATE_BINDING_TABLE_POINTERS_VS          GEN7_3D(3, 0, 0x26)
#define GEN7_3DSTATE_BINDING_TABLE_POINTERS_HS          GEN7_3D(3, 0, 0x27)
#define GEN7_3DSTATE_BINDING_TABLE_POINTERS_DS          GEN7_3D(3, 0, 0x28)
#define GEN7_3DSTATE_BINDING_TABLE_POINTERS_GS          GEN7_3D(3, 0, 0x29)
#define GEN7_3DSTATE_BINDING_TABLE_POINTERS_PS          GEN7_3D(3, 0, 0x2a)

#define GEN7_3DSTATE_SAMPLER_STATE_POINTERS_VS          GEN7_3D(3, 0, 0x2b)
#define GEN7_3DSTATE_SAMPLER_STATE_POINTERS_GS          GEN7_3D(3, 0, 0x2e)
#define GEN7_3DSTATE_SAMPLER_STATE_POINTERS_PS          GEN7_3D(3, 0, 0x2f)

#define GEN7_3DSTATE_URB_VS                             GEN7_3D(3, 0, 0x30)
#define GEN7_3DSTATE_URB_HS                             GEN7_3D(3, 0, 0x31)
#define GEN7_3DSTATE_URB_DS                             GEN7_3D(3, 0, 0x32)
#define GEN7_3DSTATE_URB_GS                             GEN7_3D(3, 0, 0x33)
/* DW1 */
# define GEN7_URB_ENTRY_NUMBER_SHIFT            0
# define GEN7_URB_ENTRY_SIZE_SHIFT              16
# define GEN7_URB_STARTING_ADDRESS_SHIFT        25

#define GEN7_3DSTATE_PUSH_CONSTANT_ALLOC_VS             GEN7_3D(3, 1, 0x12)
#define GEN7_3DSTATE_PUSH_CONSTANT_ALLOC_PS             GEN7_3D(3, 1, 0x16)
/* DW1 */
# define GEN7_PUSH_CONSTANT_BUFFER_OFFSET_SHIFT 16

struct gen7_cc_viewport {
	float min_depth;
	float max_depth;
};

#endif
