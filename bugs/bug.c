#define	DO_SANITY
/**
 *
 * $Id: List.c,v 1.31 1997/11/15 02:41:25 rwscott Exp $
 *
 * Copyright (C) 1995 Free Software Foundation, Inc.
 *
 * This file is part of the GNU LessTif Library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 **/

static char rcsid[] = "$Id: List.c,v 1.31 1997/11/15 02:41:25 rwscott Exp $";

#include <stdio.h>
#include <LTconfig.h>
#include <XmI/XmI.h>

#include <X11/Xfuncs.h>
#include <Xm/XmP.h>
#include <Xm/AtomMgr.h>
#include <Xm/DragC.h>
#include <Xm/ListP.h>
#include <Xm/ScrollBarP.h>
#include <Xm/ScrolledW.h>
#include <XmI/AtomMgrI.h>
#include <XmI/DragDropI.h>
#include <Xm/TransltnsP.h>
#include <assert.h>

#include <XmI/DebugUtil.h>

#ifndef XmUNSPECIFIED
#define XmUNSPECIFIED (~0)
#endif

/*
 * JKF: comment this out when the XmStringDrawXXX functions
 * implement their clip mask arguments.
 */
#define	JONS_CLIP_MASK_KLUDGE

/*
 * JKF: someday I won't need this
 */
#define USE_SEPARATE_ITEMS_LIST

/* Forward Declarations */

static void class_initialize();
static void class_part_initialize(WidgetClass widget_class);
static void destroy(Widget w);
static void resize(Widget w);
static void expose(Widget w, XEvent *event, Region region);
static void initialize(Widget request, Widget new_w,
		       ArgList args, Cardinal *num_args);
static Boolean set_values(Widget current, Widget request, Widget new_w,
			  ArgList args, Cardinal *num_args);
static XtGeometryResult query_geometry(Widget w,
				       XtWidgetGeometry *proposed,
				       XtWidgetGeometry *answer);

static void list_border_highlight(Widget w);
static void list_border_unhighlight(Widget w);

/* prototypes for drag-drop */
static Boolean drag_selected_proc(Widget w,
				  Atom *selection,
				  Atom *target,
				  Atom *type_return,
				  XtPointer *value_return,
				  unsigned long *length_return,
				  int *format_return);

static Boolean drag_unselected_proc(Widget w,
				    Atom *selection,
				    Atom *target,
				    Atom *type_return,
				    XtPointer *value_return,
				    unsigned long *length_return,
				    int *format_return);
static void drag_drop_finish(Widget w,
			     XtPointer client_data,
			     XtPointer call_data);

static void _XmListSetSBManageVert(Widget w, Boolean *manage_changed);
static void _XmListSetSBManageHoriz(Widget w, Boolean *manage_changed);
static void _XmListRedraw(Widget w, Boolean redraw_all_visible);

/*
 * Resources for the list class
 */
#define Offset(field) XtOffsetOf(XmListRec, list.field)
#define PrimOffset(field) XtOffsetOf(XmListRec, primitive.field)
static XtResource resources[] =
{
    {
	XmNlistSpacing, XmCListSpacing, XmRVerticalDimension,
	sizeof(Dimension), Offset(ItemSpacing),
	XmRImmediate, (XtPointer)0
    },
    {
	XmNlistMarginWidth, XmCListMarginWidth, XmRHorizontalDimension,
	sizeof(Dimension), Offset(margin_width),
	XmRImmediate, (XtPointer)0
    },
    {
	XmNlistMarginHeight, XmCListMarginHeight, XmRVerticalDimension,
	sizeof(Dimension), Offset(margin_height),
	XmRImmediate, (XtPointer)0
    },
    {
	XmNshadowThickness, XmCShadowThickness, XmRHorizontalDimension,
	sizeof(Dimension), PrimOffset(shadow_thickness),
	XmRCallProc, (XtPointer)_XmPrimitiveShadowThicknessDefault
    },
    {
	XmNhighlightThickness, XmCHighlightThickness, XmRHorizontalDimension,
	sizeof(Dimension), PrimOffset(highlight_thickness),
	XmRCallProc, (XtPointer)_XmPrimitiveHighlightThicknessDefault
    },
    {
	XmNfontList, XmCFontList, XmRFontList,
	sizeof(XmFontList), Offset(font),
	XmRImmediate, (XtPointer)NULL
    },
    {
	XmNstringDirection, XmCStringDirection, XmRStringDirection,
	sizeof(XmStringDirection), Offset(StrDir),
	XmRImmediate, (XtPointer)((XmStringDirection)XmUNSPECIFIED)
	/* this was STRING_L_TO_R */
    },
    {
	XmNitems, XmCItems, XmRXmStringTable,
	sizeof(XmStringTable), Offset(items),
	XmRStringTable, (XtPointer)NULL
    },
    {
	XmNitemCount, XmCItemCount, XmRInt,
	sizeof(int), Offset(itemCount),
	XmRImmediate, (XtPointer)0
    },
    {
	XmNselectedItems, XmCSelectedItems, XmRXmStringTable,
	sizeof(XmStringTable), Offset(selectedItems),
	XmRStringTable, (XtPointer)NULL
    },
    {
	XmNselectedItemCount, XmCSelectedItemCount, XmRInt,
	sizeof(int), Offset(selectedItemCount),
	XmRImmediate, (XtPointer)0
    },
    {
	XmNvisibleItemCount, XmCVisibleItemCount, XmRInt,
	sizeof(int), Offset(visibleItemCount),
	XmRImmediate, (XtPointer)1
    },
    {
	XmNtopItemPosition, XmCTopItemPosition, XmRTopItemPosition,
	sizeof(int), Offset(top_position),
	XmRImmediate, (XtPointer)1
    },
    {
	XmNselectionPolicy, XmCSelectionPolicy, XmRSelectionPolicy,
	sizeof(unsigned char), Offset(SelectionPolicy),
	XmRImmediate, (XtPointer)XmBROWSE_SELECT
    },
    {
	XmNlistSizePolicy, XmCListSizePolicy, XmRListSizePolicy,
	sizeof(unsigned char), Offset(SizePolicy),
	XmRImmediate, (XtPointer)XmVARIABLE
    },
    {
	XmNscrollBarDisplayPolicy, XmCScrollBarDisplayPolicy, XmRScrollBarDisplayPolicy,
	sizeof(unsigned char), Offset(ScrollBarDisplayPolicy),
	XmRImmediate, (XtPointer)XmAS_NEEDED
	/* This should be a CallProc */
    },
    {
	XmNautomaticSelection, XmCAutomaticSelection, XmRBoolean,
	sizeof(Boolean), Offset(AutoSelect),
	XmRImmediate, (XtPointer)False
    },
    {
	XmNdoubleClickInterval, XmCDoubleClickInterval, XmRInt,
	sizeof(int), Offset(ClickInterval),
	XmRImmediate, (XtPointer)XmUNSPECIFIED
	/* was XmRCallProc, (XtPointer)_XmDoubelClickIntervalDefault */
    },
    {
	XmNsingleSelectionCallback, XmCCallback, XmRCallback,
	sizeof(XtCallbackList), Offset(SingleCallback),
	XmRCallback, (XtPointer)NULL
    },
    {
	XmNmultipleSelectionCallback, XmCCallback, XmRCallback,
	sizeof(XtCallbackList), Offset(MultipleCallback),
	XmRCallback, (XtPointer)NULL
    },
    {
	XmNextendedSelectionCallback, XmCCallback, XmRCallback,
	sizeof(XtCallbackList), Offset(ExtendCallback),
	XmRCallback, (XtPointer)NULL
    },
    {
	XmNbrowseSelectionCallback, XmCCallback, XmRCallback,
	sizeof(XtCallbackList), Offset(BrowseCallback),
	XmRCallback, (XtPointer)NULL
    },
    {
	XmNdefaultActionCallback, XmCCallback, XmRCallback,
	sizeof(XtCallbackList), Offset(DefaultCallback),
	XmRCallback, (XtPointer)NULL
    },
    {
	XmNhorizontalScrollBar, XmCHorizontalScrollBar, XmRWidget,
	sizeof(Widget), Offset(hScrollBar),
	XmRImmediate, (XtPointer)NULL
    },
    {
	XmNverticalScrollBar, XmCVerticalScrollBar, XmRWidget,
	sizeof(Widget), Offset(vScrollBar),
	XmRImmediate, (XtPointer)NULL
    },
    {
	XmNnavigationType, XmCNavigationType, XmRNavigationType,
	sizeof(XmNavigationType), XtOffsetOf(XmListRec, primitive.navigation_type),
	XmRImmediate, (XtPointer)XmTAB_GROUP
    }
};

static XmSyntheticResource syn_resources[] =
{
    {
	XmNlistSpacing,
	sizeof(Dimension), Offset(ItemSpacing),
	_XmFromVerticalPixels, _XmToVerticalPixels
    },
    {
	XmNlistMarginWidth,
	sizeof(Dimension), Offset(margin_width),
	_XmFromHorizontalPixels, _XmToHorizontalPixels
    },
    {
	XmNlistMarginHeight,
	sizeof(Dimension), Offset(margin_height),
	_XmFromVerticalPixels, _XmToVerticalPixels
    },
#ifdef OLD_21MAY
/*      this resource is not of type Position; it shouldn't be here */
/* rws 8 Nov 1997 But it is in Motif???? */
    {
	XmNtopItemPosition,
	sizeof(int), Offset(top_position),
	NULL /* FIX ME */ , NULL	/* FIX ME */
    },
#endif
};

static void ListAddMode(Widget, XEvent *, String *, Cardinal *);
static void ListBeginData(Widget, XEvent *, String *, Cardinal *);
static void ListBeginDataExtend(Widget, XEvent *, String *, Cardinal *);
static void ListBeginExtend(Widget, XEvent *, String *, Cardinal *);
static void ListBeginLine(Widget, XEvent *, String *, Cardinal *);
static void ListBeginSelect(Widget, XEvent *, String *, Cardinal *);
static void ListBeginToggle(Widget, XEvent *, String *, Cardinal *);
static void ListButtonMotion(Widget, XEvent *, String *, Cardinal *);
static void ListCopyToClipboard(Widget, XEvent *, String *, Cardinal *);
static void ListDefaultAction(Widget, XEvent *, String *, Cardinal *);
static void ListEndData(Widget, XEvent *, String *, Cardinal *);
static void ListEndDataExtend(Widget, XEvent *, String *, Cardinal *);
static void ListEndExtend(Widget, XEvent *, String *, Cardinal *);
static void ListEndLine(Widget, XEvent *, String *, Cardinal *);
static void ListEndSelect(Widget, XEvent *, String *, Cardinal *);
static void ListEndToggle(Widget, XEvent *, String *, Cardinal *);
static void ListEnter(Widget, XEvent *, String *, Cardinal *);
static void ListExtendNextItem(Widget, XEvent *, String *, Cardinal *);
static void ListExtendPrevItem(Widget, XEvent *, String *, Cardinal *);
static void ListFocusIn(Widget, XEvent *, String *, Cardinal *);
static void ListFocusOut(Widget, XEvent *, String *, Cardinal *);
static void ListKbdActivate(Widget, XEvent *, String *, Cardinal *);
static void ListKbdBeginExtend(Widget, XEvent *, String *, Cardinal *);
static void ListKbdBeginSelect(Widget, XEvent *, String *, Cardinal *);
static void ListKbdCancel(Widget, XEvent *, String *, Cardinal *);
static void ListKbdDeSelectAll(Widget, XEvent *, String *, Cardinal *);
static void ListKbdEndExtend(Widget, XEvent *, String *, Cardinal *);
static void ListKbdEndSelect(Widget, XEvent *, String *, Cardinal *);
static void ListKbdSelectAll(Widget, XEvent *, String *, Cardinal *);
static void ListLeftChar(Widget, XEvent *, String *, Cardinal *);
static void ListLeave(Widget, XEvent *, String *, Cardinal *);
static void ListLeftPage(Widget, XEvent *, String *, Cardinal *);
static void ListNextItem(Widget, XEvent *, String *, Cardinal *);
static void ListNextPage(Widget, XEvent *, String *, Cardinal *);
static void ListPrevItem(Widget, XEvent *, String *, Cardinal *);
static void ListPrevPage(Widget, XEvent *, String *, Cardinal *);
static void ListProcessDrag(Widget, XEvent *, String *, Cardinal *);
static void ListRightChar(Widget, XEvent *, String *, Cardinal *);
static void ListRightPage(Widget, XEvent *, String *, Cardinal *);

static XtActionsRec actions[] =
{
    {"ListButtonMotion", ListButtonMotion},


    {"ListBeginExtend", ListBeginExtend},
    {"ListEndExtend", ListEndExtend},


    {"ListBeginToggle", ListBeginToggle},
    {"ListEndToggle", ListEndToggle},





    {"ListBeginSelect", ListBeginSelect},
    {"ListEndSelect", ListEndSelect},
    {"ListKbdBeginSelect", ListKbdBeginSelect},
    {"ListKbdEndSelect", ListKbdEndSelect},





    {"ListKbdBeginExtend", ListKbdBeginExtend},
    {"ListKbdEndExtend", ListKbdEndExtend},



    {"ListKbdSelectAll", ListKbdSelectAll},
    {"ListKbdDeSelectAll", ListKbdDeSelectAll},
    {"ListKbdActivate", ListKbdActivate},
    {"ListKbdCancel", ListKbdCancel},
    {"ListAddMode", ListAddMode},
    {"ListPrevItem", ListPrevItem},
    {"ListNextItem", ListNextItem},
    {"ListPrevPage", ListPrevPage},
    {"ListNextPage", ListNextPage},
    {"ListLeftChar", ListLeftChar},
    {"ListLeftPage", ListLeftPage},
    {"ListRightChar", ListRightChar},
    {"ListRightPage", ListRightPage},









    {"ListExtendPrevItem", ListExtendPrevItem},
    {"ListExtendNextItem", ListExtendNextItem},



    {"ListBeginLine", ListBeginLine},
    {"ListEndLine", ListEndLine},
    {"ListBeginData", ListBeginData},
    {"ListEndData", ListEndData},
    {"ListBeginDataExtend", ListBeginDataExtend},
    {"ListEndDataExtend", ListEndDataExtend},
    {"ListFocusIn", ListFocusIn},
    {"ListFocusOut", ListFocusOut},
    {"ListEnter", ListEnter},
    {"ListLeave", ListLeave},



    {"ListCopyToClipboard", ListCopyToClipboard},
    {"ListProcessDrag", ListProcessDrag},

    {"ListDefaultAction", ListDefaultAction},
};

/* *INDENT-OFF* */
static XmBaseClassExtRec _XmListCoreClassExtRec = {
    /* next_extension            */ NULL,
    /* record_type               */ NULLQUARK,                             
    /* version                   */ XmBaseClassExtVersion,
    /* size                      */ sizeof(XmBaseClassExtRec),
    /* initialize_prehook        */ NULL,
    /* set_values_prehook        */ NULL,
    /* initialize_posthook       */ NULL,
    /* set_values_posthook       */ NULL,
    /* secondary_object_class    */ NULL,
    /* secondary_object_create   */ NULL,
    /* get_secondary_resources   */ NULL,
    /* fast_subclass             */ { 0 },
    /* get_values_prehook        */ NULL,
    /* get_values_posthook       */ NULL,
    /* class_part_init_prehook   */ NULL,
    /* class_part_init_posthook  */ NULL,
    /* ext_resources             */ NULL,
    /* compiled_ext_resources    */ NULL,
    /* num_ext_resources         */ 0,
    /* use_sub_resources         */ False,
    /* widget_navigable          */ XmInheritWidgetNavigable,
    /* focus_change              */ XmInheritFocusChange,
    /* wrapper_data              */ NULL
};

XmPrimitiveClassExtRec _XmListPrimClassExtRec = {
    /* next_extension      */ NULL,
    /* record_type         */ NULLQUARK,
    /* version             */ XmPrimitiveClassExtVersion,
    /* record_size         */ sizeof(XmPrimitiveClassExtRec),
    /* widget_baseline     */ NULL, /* FIX ME */
    /* widget_display_rect */ NULL, /* FIX ME */
    /* widget_margins      */ NULL  /* FIX ME */
};

XmListClassRec xmListClassRec = {
    /* Core class part */
    {
      /* superclass            */ (WidgetClass) &xmPrimitiveClassRec,
      /* class_name            */ "XmList",
      /* widget_size           */ sizeof(XmListRec),
      /* class_initialize      */ class_initialize,
      /* class_part_initialize */ class_part_initialize,
      /* class_inited          */ False,
      /* initialize            */ initialize,
      /* initialize_hook       */ NULL,
      /* realize               */ XtInheritRealize,
      /* actions               */ actions,
      /* num_actions           */ XtNumber(actions),
      /* resources             */ resources,
      /* num_resources         */ XtNumber(resources),
      /* xrm_class             */ NULLQUARK,
      /* compress_motion       */ True,
      /* compress_exposure     */ XtExposeCompressMaximal,
      /* compress_enterleave   */ True,
      /* visible_interest      */ False,
      /* destroy               */ destroy,
      /* resize                */ resize,
      /* expose                */ expose,
      /* set_values            */ set_values,
      /* set_values_hook       */ NULL,
      /* set_values_almost     */ XtInheritSetValuesAlmost,
      /* get_values_hook       */ NULL,
      /* accept_focus          */ NULL,
      /* version               */ XtVersion,
      /* callback offsets      */ NULL,
      /* tm_table              */ _XmList_ListXlations1,
      /* query_geometry        */ query_geometry,
      /* display_accelerator   */ NULL,
      /* extension             */ (XtPointer)&_XmListCoreClassExtRec
    },
    /* Primitive Class part */
    {
	/* border_highlight      */ list_border_highlight,
       	/* border_unhighlight    */ list_border_unhighlight,
       	/* translations          */ XtInheritTranslations,
       	/* arm_and_activate_proc */ NULL,
       	/* synthetic resources   */ syn_resources, 
        /* num syn res           */ XtNumber(syn_resources),
	/* extension             */ (XtPointer)&_XmListPrimClassExtRec
    },
    /* List Class part */
    {
      /* extension */ NULL
    }
};
/* *INDENT-ON* */

WidgetClass xmListWidgetClass = (WidgetClass)&xmListClassRec;

/************************ local functions ************************/

/************************************/
/* List item memory [de]allocation */
/**********************************/
/*
 * This function allocates or reallocates the item list
 */
void
_XmListReallocItems(Widget w)
{
    int item_count = List_ItemCount(w);

    if (item_count == 0)
    {
	XtFree((XtPointer)List_Items(w));

	List_Items(w) = NULL;

	XtFree((XtPointer)List_InternalList(w));

	List_InternalList(w) = NULL;
    }
    else
    {
	List_Items(w) =
	    (XmStringTable)XtRealloc((XtPointer)List_Items(w),
				     item_count * sizeof(XmString *));

	List_InternalList(w) =
	    (ElementPtr *)XtRealloc((XtPointer)List_InternalList(w),
				    item_count * sizeof(ElementPtr));
    }
}

/*
 * This function allocates or reallocates the selected item list
 */
void
_XmListReallocSelectedItems(Widget w)
{
    int item_count = List_ItemCount(w);

    /*
     * the selected items list is the same size as the items list
     */
    if (item_count == 0)
    {
	XtFree((XtPointer)List_SelectedItems(w));

	List_SelectedItems(w) = NULL;

	XtFree((XtPointer)List_SelectedIndices(w));

	List_SelectedIndices(w) = NULL;
    }
    else
    {
	List_SelectedItems(w) =
	    (XmStringTable)XtRealloc((XtPointer)List_SelectedItems(w),
				     item_count * sizeof(XmString));

	List_SelectedIndices(w) =
	    (int *)XtRealloc((XtPointer)List_SelectedIndices(w),
			     item_count * sizeof(int));
    }
}

static void
_XmListFreeItems(Widget w)
{
    int i;

    for (i = 0; i < List_ItemCount(w); i++)
    {
	XmStringFree((XtPointer)List_Items(w)[i]);

	XtFree((XtPointer)List_InternalList(w)[i]);
    }

    XtFree((XtPointer)List_Items(w));
    XtFree((XtPointer)List_InternalList(w));

}

static void
_XmListFreeSelectedItems(Widget w)
{
    int i;

    for (i = 0; i < List_ItemCount(w); i++)
    {
	XmStringFree((XtPointer)List_SelectedItems(w)[i]);

	XtFree((XtPointer)List_SelectedIndices(w)[i]);
    }

    XtFree((XtPointer)List_SelectedItems(w));

    XtFree((XtPointer)List_SelectedIndices(w));

}

/**********************************/
/* Geometry management functions */
/********************************/
static Dimension
_XmListBestHeight(Widget w)
{
    int highlight = Prim_HighlightThickness(w);

    return (List_VisibleItemCount(w) * (List_MaxItemHeight(w) + highlight + 1) +
	    highlight + 1 +
	    2 * (List_MarginHeight(w) + Prim_ShadowThickness(w)) +
	    (List_VisibleItemCount(w) - 1) * (List_ItemSpacing(w)));
}

static Dimension
_XmListBestWidth(Widget w)
{
    int highlight = Prim_HighlightThickness(w);

    if (List_ItemCount(w) > 0)
    {
	return (List_MaxWidth(w) + 2 * (Prim_ShadowThickness(w) +
					List_MarginWidth(w) + highlight + 1));
    }
    /* special case, if there are no items in list */
    else
    {
	return (List_VisibleItemCount(w) * (List_MaxItemHeight(w)) +
		(List_VisibleItemCount(w) - 1) *
		(List_ItemSpacing(w) + highlight + 1)) / 2 +
	    2 * (Prim_ShadowThickness(w) + List_MarginWidth(w) +
		 highlight + 1);
    }
}

static Dimension
_XmListAvailableWidth(Widget w)
{
    return (XtWidth(w) - 2 * (Prim_ShadowThickness(w) + List_MarginWidth(w) +
			      Prim_HighlightThickness(w) + 1));
}

static void
_XmListRecalcItems(Widget w, Boolean *redraw_all)
{
    /* Sets the VisibleItemCount based on the current geometry */
    int nitems;
    int highlight = Prim_HighlightThickness(w);
    Dimension available_height = (XtHeight(w) -
				  2 * (highlight + List_MarginHeight(w)));

    nitems = (available_height - (highlight + 1) + List_ItemSpacing(w)) /
	(List_MaxItemHeight(w) + List_ItemSpacing(w) + highlight + 1);

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "XmListRecalcItems => nitems: %d item height: %d\n",
		      nitems, List_MaxItemHeight(w)));

    if (nitems <= 0)
    {
	nitems = 1;
    }

    if (nitems != List_VisibleItemCount(w))
    {
	List_VisibleItemCount(w) = nitems;

	*redraw_all = True;
    }

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListRecalcItems => w: %d h: %d, "
		      "VisibleItemCount %d\n", XtWidth(w), XtHeight(w),
		      List_VisibleItemCount(w)));
}

static void
_XmListCalculateInitialGeometry(Widget new_w, Widget request)
{
    Boolean redraw_all = False;	/* Dummy var */

    DEBUGOUT(XdbDebug(__FILE__, new_w,
		    "_XmListCalculateInitialGeometry => VisibleItemCount %d\n",
		      List_VisibleItemCount(new_w)));

    if (XtHeight(request) == 0 || XtWidth(request) == 0)
    {
	XtWidth(new_w) = _XmListBestWidth(new_w);
	XtHeight(new_w) = _XmListBestHeight(new_w);
    }
    else
    {
	_XmListRecalcItems(new_w, &redraw_all);
    }
}

static void
_XmListSetGeometry(Widget w)
{
    XtGeometryResult result;
    XtWidgetGeometry geo;
    Dimension desired_width, desired_height;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListSetGeometry()\n"));

    /* NOTE: This function needs to be Single Entry/Single Exit */
    List_FromSetNewSize(w) = True;

    /* Calculate the dimensions needed to display VisibleItemCount items */
    desired_width = _XmListBestWidth(w);
    desired_height = _XmListBestHeight(w);

    /*
     * no geometry changes needed if ListSizePolicy is CONSTANT
     * ListSizePolicy only controls the horizontal scrollbar policy
     * But what if we're called from SetValues?
     *
     *  if (List_SizePolicy(w) == XmCONSTANT) return;
     */

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetGeometry() first desired w: %d, h: %d\n",
		      (int)desired_width, (int)desired_height));

    /* This needs to take into account whether the width has been changed
     * by set_values */
    if ((List_SizePolicy(w) == XmVARIABLE && XtWidth(w) > desired_width) ||
	(List_SizePolicy(w) == XmCONSTANT && XtIsRealized(w)))
    {
	desired_width = XtWidth(w);
    }

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetGeometry() desired w: %d, h: %d\n",
		      (int)desired_width, (int)desired_height));

    if (List_IsScrolledList(w))
    {
	Boolean manage_changed;

	_XmListSetSBManageVert(w, &manage_changed);
	_XmListSetSBManageHoriz(w, &manage_changed);
    }

    geo.request_mode = CWWidth | CWHeight;
    geo.width = desired_width;
    geo.height = desired_height;
    result = _XmMakeGeometryRequest((Widget)w, &geo);

    List_FromSetNewSize(w) = False;
}


static void
_XmListHighlight(Widget w)
{
    int line_type = LineSolid;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListHighlight()\n"));

    if (List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	List_SelectionPolicy(w) == XmMULTIPLE_SELECT)
    {
	line_type = LineOnOffDash;

	/* this is a special case  */
	if (List_LastHLItem(w) < 1 || List_LastHLItem(w) > List_ItemCount(w))
	{
	    List_LastHLItem(w) = 0;
	}
    }
    else if (List_SelectionPolicy(w) == XmBROWSE_SELECT ||
	     List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	line_type = LineSolid;
    }

    if (List_ItemCount(w) == 0 ||
	List_LastHLItem(w) > (List_TopPosition(w) +
			      List_VisibleItemCount(w) - 1) ||
	List_LastHLItem(w) < List_TopPosition(w))
    {
	_XmDrawHighlight(XtDisplay(w), XtWindow(w), Prim_HighlightGC(w),
			 (Position)(Prim_ShadowThickness(w) +
				    List_MarginWidth(w)),
			 (Position)(Prim_ShadowThickness(w) +
				    List_MarginHeight(w)),
			 (Dimension)(XtWidth(w) - 2 * (List_MarginWidth(w) +
					  Prim_ShadowThickness(w))),
			 (Dimension)(XtHeight(w) - 2 * (List_MarginHeight(w) +
						     Prim_ShadowThickness(w))),
			 Prim_HighlightThickness(w),
			 line_type);
    }
    else
    {
	int itemHeight = List_MaxItemHeight(w) + Prim_HighlightThickness(w) +
			1 + List_ItemSpacing(w);

	_XmDrawHighlight(XtDisplay(w),
			 XtWindow(w),
			 Prim_HighlightGC(w),
			 (Position)(Prim_ShadowThickness(w) +
				    List_MarginWidth(w)),
			 (Position)(Prim_ShadowThickness(w) +
				    List_MarginHeight(w)
				 + (List_LastHLItem(w) - List_TopPosition(w)) *
				    itemHeight),
			 (Dimension)(XtWidth(w) - 2 * (List_MarginWidth(w) +
						     Prim_ShadowThickness(w))),
			 (Dimension)(List_MaxItemHeight(w) +
				     2 * (Prim_HighlightThickness(w) + 1)),
			 Prim_HighlightThickness(w),
			 line_type);
    }
}

static void
_XmListUnhighlight(Widget w)
{

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListUnhighlight()\n"));

    if (List_ItemCount(w) == 0 ||
	List_LastHLItem(w) > (List_TopPosition(w) +
			      List_VisibleItemCount(w) - 1) ||
	List_LastHLItem(w) < List_TopPosition(w))
    {
	DEBUGOUT(XdbDebug(__FILE__, w, "_XmListUnhighlight() border\n"));

	_XmClearBorder(XtDisplay(w),
		       XtWindow(w),
		       (Position)(Prim_ShadowThickness(w) +
				  List_MarginWidth(w)),
		       (Position)(Prim_ShadowThickness(w) +
				  List_MarginHeight(w)),
		       (Dimension)(XtWidth(w) - 2 * (List_MarginWidth(w) +
						     Prim_ShadowThickness(w))),
		       (Dimension)(XtHeight(w) - 2 * (List_MarginHeight(w) +
						      Prim_ShadowThickness(w))),
		       Prim_HighlightThickness(w));
    }
    else
    {
	int itemHeight = List_MaxItemHeight(w) + Prim_HighlightThickness(w) +
			1 + List_ItemSpacing(w);

	DEBUGOUT(XdbDebug(__FILE__, w, "_XmListUnhighlight() item\n"));

	/*
	 * This call used to clear the entire list again in many cases when
	 * a list is used as a ScrolledList, especially in a dialog box.
	 * The reason was that the final parameter, if 0, was used in Xlib
	 * calls which translate that into "take the entire window".
	 * Danny 28/2/1997
	 */
	DEBUGOUT(XdbDebug(__FILE__, w,
			  "_XmClearBorder(x %d, y %d, w %d, h %d, st %d)\n",
			  (Position)(Prim_ShadowThickness(w) +
				     List_MarginWidth(w)),
			  (Position)(Prim_ShadowThickness(w) +
				     List_MarginHeight(w) +
				     (List_LastHLItem(w) -
				      List_TopPosition(w)) * itemHeight),
			  (Dimension)(XtWidth(w) - 2 * (List_MarginWidth(w) +
						     Prim_ShadowThickness(w))),
			  (Dimension)(List_MaxItemHeight(w) +
				      2 * (Prim_HighlightThickness(w) + 1)),
			  Prim_HighlightThickness(w)));

	_XmClearBorder(XtDisplay(w), XtWindow(w),
		       (Position)(Prim_ShadowThickness(w) +
				  List_MarginWidth(w)),
		       (Position)(Prim_ShadowThickness(w) +
				  List_MarginHeight(w) +
				  (List_LastHLItem(w) - List_TopPosition(w)) *
				  itemHeight),
		       (Dimension)(XtWidth(w) - 2 * (List_MarginWidth(w) +
						     Prim_ShadowThickness(w))),
		       (Dimension)(List_MaxItemHeight(w) +
				   2 * (Prim_HighlightThickness(w) + 1)),
		       Prim_HighlightThickness(w));

    }
}


/************************************/
/* Scrollbar init/update functions */
/**********************************/

/* Manage the vertical, if necessary */
static void
_XmListSetSBManageVert(Widget w, Boolean *manage_changed)
{

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetSBManageVert(%s) DisplayPolicy=%s\n",
		      XtIsManaged(List_VSB(w)) ? "managed" : "unmanaged",
		      (List_SBDisplayPolicy(w) == XmAS_NEEDED)
		      ? "AS_NEEDED"
		      : "STATIC"));

    *manage_changed = False;

    if (List_SBDisplayPolicy(w) == XmAS_NEEDED)
    {

	if (XtIsManaged(List_VSB(w)) &&
	    List_VisibleItemCount(w) >= List_ItemCount(w))
	{
	    XtUnmanageChild((Widget)List_VSB(w));

	    *manage_changed = True;
	}
	else if (!XtIsManaged(List_VSB(w)) &&
		 List_VisibleItemCount(w) < List_ItemCount(w))
	{
	    XtManageChild((Widget)List_VSB(w));

	    *manage_changed = True;

	    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListSetSBManageVert(%s) 1\n",
			      XtIsManaged(List_VSB(w))
			      ? "managed"
			      : "unmanaged"));
	}
    }
    else
    {
	if (!XtIsManaged(List_VSB(w)))
	{
	    XtManageChild((Widget)List_VSB(w));

	    *manage_changed = True;

	    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListSetSBManageVert(%s) 2\n",
			      XtIsManaged(List_VSB(w))
			      ? "managed"
			      : "unmanaged"));
	}
    }

    XmUpdateDisplay((Widget)List_VSB(w));

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListSetSBManageVert(%s) leaving\n",
		      XtIsManaged(List_VSB(w))
		      ? "managed"
		      : "unmanaged"));
}


/*************************************************************************/
/* Manage the horizontal, if necessary                                   */
/*                                                                       */
/* Motif 1.2.x has a bug/feature related to the resources                */
/* XmNscrollBarDisplayPolicy and XmNlistSizePolicy.  The value of        */
/* XmNscrollBarDisplayPolicy seems to have some effect on the value      */
/* of XmNlistSizePolicy.                                                 */
/*                                                                       */
/* if XmNscrollBarDisplayPolicy                                          */
/* is this, and the value of XmNlistSizePolicy is this,                  */
/*     |                                            |                    */
/*     |                                            |                    */
/*     |            .------------.---------------------------.           */
/*     |            |            |                           |           */
/*     |            V            V                           V           */
/*     |        XmVARIABLE   XmCONSTANT             XmRESIZE_IF_POSSIBLE */
/*     V       --------------------------------------------------------- */
/*             |                                                         */
/* XmSTATIC    |XmVARIABLE   XmCONSTANT             XmCONSTANT           */
/*             |                                                         */
/*             |                                                         */
/* XmAS_NEEDED |XmVARIABLE   XmRESIZE_IF_POSSIBLE,  XmRESIZE_IF_POSSIBLE */
/*             |             but reserves space                          */
/*             |             for horiz scrollbar                         */
/*             --------------------------------------------------------- */
/*                  ^            ^                           ^           */
/*              then the effective XmNlistSizePolicy value is here       */
/*                                                                       */
/*************************************************************************/
static void
_XmListSetSBManageHoriz(Widget w, Boolean *manage_changed)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		    "_XmListSetSBManageHoriz(%s) - avail, max width = %d %d\n",
		      XtIsManaged(List_HSB(w)) ? "managed" : "unmanaged",
		      _XmListAvailableWidth(w),
		      List_MaxWidth(w)));

    *manage_changed = False;

    if (List_SizePolicy(w) == XmRESIZE_IF_POSSIBLE)
    {
	if (XtIsManaged(List_HSB(w)) &&
	    _XmListAvailableWidth(w) >= List_MaxWidth(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListSetSBManageHoriz(%s) - unmanaging",
			   XtIsManaged(List_HSB(w)) ? "managed" : "unmanaged");

		     XtUnmanageChild((Widget)List_HSB(w)));

	    *manage_changed = True;
	}
	else if (!XtIsManaged(List_HSB(w)) &&
		 _XmListAvailableWidth(w) < List_MaxWidth(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListSetSBManageHoriz(%s) - managing",
			  XtIsManaged(List_HSB(w)) ? "managed" : "unmanaged"));

	    XtManageChild((Widget)List_HSB(w));

	    *manage_changed = True;
	}
    }
    else if (List_SizePolicy(w) == XmCONSTANT)
    {
	if (!XtIsManaged(List_HSB(w)))
	{
	    XtManageChild((Widget)List_HSB(w));

	    *manage_changed = True;
	}
    }
    else if (List_SizePolicy(w) == XmVARIABLE)
    {
	if (XtIsManaged(List_HSB(w)) &&
	    _XmListAvailableWidth(w) >= List_MaxWidth(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListSetSBManageHoriz(%s) - unmanaging",
			  XtIsManaged(List_HSB(w)) ? "managed" : "unmanaged"));

	    XtUnmanageChild((Widget)List_HSB(w));

	    *manage_changed = True;
	}
	else if (!XtIsManaged(List_HSB(w)) &&
		 _XmListAvailableWidth(w) < List_MaxWidth(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListSetSBManageHoriz(%s) - managing",
			  XtIsManaged(List_HSB(w)) ? "managed" : "unmanaged"));

	    XtManageChild((Widget)List_HSB(w));

	    *manage_changed = True;
	}
    }
}


/* Initialises the scrollbars' min, max and extent values
 * The scrollbars need to be updated together to prevent re-entrancy 
 * problems */
static void
_XmListInitScrollBars(Widget w, Boolean horiz, Boolean vert)
{
    Boolean manage_changed = False;
    int old_Horigin;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListInitScrollBars() %s %s %s\n",
		      horiz ? "Horizontal" : "",
		      vert ? "Vertical" : "",
		      List_FromSetSB(w) ? "... Re-entered!" : ""));

    /*
     * As managing the scrollbars causes the Scrolled Window parent to 
     * resize the list, this function can be called recursively.  This 
     * bit of code avoids race conditions caused by that.
     */
    if (!List_IsScrolledList(w) || List_FromSetSB(w))
    {
	return;
    }

    List_FromSetSB(w) = True;

    /*
     * Changing the management of one scrollbar can require a change in
     * the other... this should handle all cases though.... I think
     */
    _XmListSetSBManageVert(w, &manage_changed);
    _XmListSetSBManageHoriz(w, &manage_changed);
    _XmListSetSBManageVert(w, &manage_changed);

    if (manage_changed)
    {
	horiz = vert = True;
    }

    if (horiz)
    {
	if (List_ItemCount(w) == 0 || List_MaxWidth(w) == 0)
	{
	    List_Hmin(w) = 0;
	    List_Hmax(w) = 1;
	    List_Hextent(w) = 1;
	    List_Horigin(w) = 0;
	}
	else
	{
	    List_Hmin(w) = 0;

	    List_Hmax(w) = List_MaxWidth(w) - 1;

	    /*
	     * Here's a weird situation: if the list is created with 0
	     * elements, XtWidth(w) is equal to the sum of all the border
	     * areas, like the shadow, highlight, etc..., so the available
	     * width is actually ZERO.  In this case, I think we should
	     * set Hextent(w) to be the same as Hmax(w).
	     */
	    if (List_Hmax(w) > _XmListAvailableWidth(w) &&
		_XmListAvailableWidth(w) > 0)
	    {
		/*
		 * set slider size to be the available width of the list
		 */
		List_Hextent(w) = _XmListAvailableWidth(w);

	    }
	    else
	    {
		/*
		 * whole list is visible horizontally, so slider size
		 * is set to Hmax - Hmin, which equals Hmax
		 */
		List_Hextent(w) = List_Hmax(w);
	    }
	}

	old_Horigin = List_Horigin(w);

	if (List_Horigin(w) < 0)
	{
	    List_Horigin(w) = 0;
	}
	else if (List_Horigin(w) > List_Hmax(w) - List_Hextent(w))
	{
	    List_Horigin(w) = List_Hmax(w) - List_Hextent(w);
	}

	XtVaSetValues((Widget)List_HSB(w),
		      XmNmaximum, List_Hmax(w),
		      XmNminimum, List_Hmin(w),
		      XmNincrement, 10 /*List_CharWidth(w) */ ,
		      XmNsliderSize, List_Hextent(w),
		      XmNvalue, List_Horigin(w),
		      NULL);
	/*
	 * this is a kluge.  I call the valueChanged callback manually
	 */
	if (List_Horigin(w) != old_Horigin)
	{
	    XmScrollBarCallbackStruct cbs;
	    Widget sb = (Widget)List_HSB(w);

	    cbs.event = NULL;
	    cbs.value = List_Horigin(w);
	    cbs.reason = XmCR_VALUE_CHANGED;
	    cbs.pixel = 0;

	    XtCallCallbackList(sb, SCB_ValueChangedCallback(sb), &cbs);
	}

	DEBUGOUT(XdbDebug(__FILE__, w,
			  "_XmListInitScrollBars() horiz - max, min, "
		     "slider, val = %d %d %d %d\n", List_Hmax(w), List_Hmin(w),
			  List_Hextent(w), List_Horigin(w)));

    }

    if (vert)
    {
	int page_inc;

	List_Vmin(w) = 0;

	if (List_ItemCount(w) == 0 || List_VisibleItemCount(w) == 0)
	{
	    List_Vorigin(w) = 0;
	    List_Vextent(w) = 100;
	    List_Vmax(w) = 100;
	    page_inc = 10;
	}
	else
	{
	    if (List_TopPosition(w) < 0)
	    {
		List_TopPosition(w) = 0;
	    }

	    List_Vorigin(w) = List_TopPosition(w) - 1;

	    if (List_Vorigin(w) < 0)
	    {
		List_Vorigin(w) = 0;
	    }

	    List_Vextent(w) = List_VisibleItemCount(w);

	    if (List_ItemCount(w) < List_VisibleItemCount(w))
	    {
		List_Vmax(w) = List_VisibleItemCount(w);
	    }
	    else
	    {
		List_Vmax(w) = List_ItemCount(w);
	    }

	    if (List_Vorigin(w) > List_Vmax(w) - List_Vextent(w))
	    {
		List_Vorigin(w) = List_Vmax(w) - List_Vextent(w);
	    }
	    page_inc = List_Vextent(w) - 1;

	}

	/* rws 21 Jun 1997
	 * page_inc is set in the if above, so let's just check its range
	 * and use it.
	 */
	if (page_inc < 1)
	{
	    page_inc = 1;
	}

	DEBUGOUT(XdbDebug(__FILE__, w,
			  "_XmListInitScrollBars: slider, page, value, max,"
			  " count, visible, top =%d, %d, %d, %d, %d, %d, %d\n",
			List_Vextent(w), page_inc /* rws List_Vextent(w)-1 */ ,
			  List_Vorigin(w), List_Vmax(w),
			  List_ItemCount(w), List_VisibleItemCount(w),
			  List_TopPosition(w)));

	XtVaSetValues((Widget)List_VSB(w),
		      XmNmaximum, List_Vmax(w),
		      XmNminimum, List_Vmin(w),
		      XmNsliderSize, List_Vextent(w),
		      XmNvalue, List_Vorigin(w),
		      XmNpageIncrement, page_inc /* rws List_Vextent(w)-1 */ ,
		      NULL);
    }

    List_FromSetSB(w) = False;

    XmUpdateDisplay(w);

}

/* Set the position of the horizontal scrollbar */
static void
_XmListUpdateHorizScrollBar(Widget w, int origin, Boolean *redraw_all)
{
    if (!List_IsScrolledList(w))
    {
	return;
    }

    if (origin < List_Hmin(w))
    {
	origin = List_Hmin(w);
    }
    else if (origin > List_Hmax(w) - List_Hextent(w))
    {
	origin = List_Hmax(w) - List_Hextent(w);
    }

    if (origin != List_Horigin(w))
    {
	List_XOrigin(w) = List_Horigin(w) = origin;

	XtVaSetValues((Widget)List_HSB(w), XmNvalue, List_Horigin(w), NULL);

	*redraw_all = True;
    }
}

/* Updates the origin of the vertical scrollbar based on the TopPosition */
static void
_XmListUpdateVertScrollBar(Widget w)
{
    if (!List_IsScrolledList(w))
    {
	return;
    }

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListUpdateVertScrollBar: value = %d\n",
		      List_TopPosition(w)));

    if (List_Vorigin(w) != List_TopPosition(w) - 1)
    {
	List_Vorigin(w) = List_TopPosition(w) - 1;

	if (List_Vorigin(w) < 0)
	{
	    List_Vorigin(w) = 0;
	}

	XtVaSetValues((Widget)List_VSB(w), XmNvalue, List_Vorigin(w), NULL);
    }
}

/*******************************/
/* List item addition/removal */
/*****************************/

/* Add items to the list in an unselected state */
static void
_XmListAddItemsUnselected(Widget w,
			  XmString *items,
			  int item_count,
			  int position)
{
    int i, n;
    Dimension width, height, max_width = 0, max_height = 0;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListAddItemsUnselected (itemCount %d)\n",
		      List_ItemCount(w)));

    if (List_ItemCount(w) == 0)
    {
	position = 0;
    }
    else if (position < 0 || position > (List_ItemCount(w) + 1))
    {
	DEBUGOUT(XdbDebug(__FILE__, w,
			  "_XmListAddItemsUnselected (itemCount %d) : "
			  "illegal position %d\n",
			  List_ItemCount(w), position));
	return;
    }

    List_ItemCount(w) += item_count;

    /*
     *  resize List_Items(w) and List_SelectedItems(w) to accomodate
     *  the added items
     */
    _XmListReallocItems(w);
    _XmListReallocSelectedItems(w);

    if (position == 0)
    {
	position = List_ItemCount(w) - item_count + 1;
    }
    else
    {
	/* Shuffle the items down the list */
	for (i = List_ItemCount(w) - 1; i >= position - 1 + item_count; i--)
	{
	    List_Items(w)[i] = List_Items(w)[i - item_count];

	    List_InternalList(w)[i] = List_InternalList(w)[i - item_count];

	    List_InternalList(w)[i]->LastTimeDrawn = False;
	}
    }

    /* Insert the elements */
    for (i = position - 1, n = 0; n < item_count; i++, n++)
    {
	XmStringExtent(List_Font(w), items[n], &width, &height);

#ifdef USE_SEPARATE_ITEMS_LIST
	List_Items(w)[i] = XmStringCopy(items[n]);
#endif
	List_InternalList(w)[i] = (ElementPtr)XtMalloc(sizeof(Element));
	List_InternalList(w)[i]->name = _XmStringCreate(items[n]);
	List_InternalList(w)[i]->selected =
	    List_InternalList(w)[i]->last_selected =
	    List_InternalList(w)[i]->LastTimeDrawn = False;

	/*
	 *   Don't forget that each "line" can consist of multiple lines.
	 *   I don't think I handle that properly yet.
	 */
	List_InternalList(w)[i]->NumLines = XmStringLineCount(items[n]);
	List_InternalList(w)[i]->length = XmStringLength(items[n]);
	List_InternalList(w)[i]->height = height;
	List_InternalList(w)[i]->width = width;

#ifdef USE_CUM_HEIGHT
	List_InternalList(w)[i]->CumHeight = height +
	    ((i == 0) ? Prim_ShadowThickness(w) :
	     List_InternalList(w)[i - 1]->CumHeight +
	     2 * Prim_HighlightThickness(w) +
	     List_ItemSpacing(w));
#endif
	if (height > max_height)
	{
	    max_height = height;
	}
	if (width > max_width)
	{
	    max_width = width;
	}
    }

    if (max_width > List_MaxWidth(w) || max_height > List_MaxItemHeight(w))
    {
	if (max_width > List_MaxWidth(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListAddItemsUnselected(%i): MaxItemWidth: %d\n",
			      __LINE__,max_width));

	    List_MaxWidth(w) = max_width;
	}

	if (max_height > List_MaxItemHeight(w))
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListAddItemsUnselected: MaxItemHeight: %d\n",
			      max_height));

	    List_MaxItemHeight(w) = max_height;
	}

#define GEOM
#ifdef GEOM
	_XmListSetGeometry(w);
#endif
    }

#ifdef USE_CUM_HEIGHT
    /* Update CumHeight for all elements below the inserted ones */
    for (i = position - 1 + item_count; i < List_ItemCount(w); i++)
    {
	List_InternalList(w)[i]->CumHeight = ((i == 0)
		     ? Prim_ShadowThickness(w) + Prim_HighlightThickness(w) + 1
				    : List_InternalList(w)[i - 1]->CumHeight) +
	    List_InternalList(w)[i]->height +
	    1 + Prim_HighlightThickness(w) + List_ItemSpacing(w);
    }
#endif

    /* List_ItemCount has changed, so re-initialise the scrollbars */
    _XmListInitScrollBars(w, True, True);
}

/* Inserts an item in the list */
static void
_XmListAddItemUnselected(Widget w,
			 XmString item,
			 int position)
{
    _XmListAddItemsUnselected(w, &item, 1, position);

    _XmListSetGeometry(w);

    _XmListRedraw(w, True);

}

/* Deletes the item at position <position> */
static void
_XmListDeletePos(Widget w, int position)
{
    int i;
    Dimension height, max_width_so_far, max_height_so_far;
    Boolean is_selected;

    if (position < 0 || position > List_ItemCount(w))
    {
	return;
    }

    if (!position)
    {
	position = List_ItemCount(w);
    }

    /*
     * This seems to be a quirk of Motif.  When the last selected item is
     * deleted, the last selected item position is decremented, unless it
     * is the first item
     */
    if (position == List_LastHLItem(w) && position != 1)
    {
	/*
	 * Looks like last_selected is not yet implemented, but I'll do
	 * this anyway
	 */
	List_InternalList(w)[List_LastHLItem(w) - 1]->last_selected = False;

	List_LastHLItem(w)--;

	List_InternalList(w)[List_LastHLItem(w) - 1]->last_selected = True;
    }

    height = List_InternalList(w)[position - 1]->height;

    /* Free the item's memory */
#ifdef USE_SEPARATE_ITEMS_LIST
    XmStringFree(List_Items(w)[position - 1]);
#endif

    XtFree((XtPointer)List_InternalList(w)[position - 1]);

    /* Shuffle the other items down */
    for (i = position - 1; i < List_ItemCount(w); i++)
    {
#ifdef USE_SEPARATE_ITEMS_LIST
	List_Items(w)[i] = List_Items(w)[i + 1];
#endif

	List_InternalList(w)[i] = List_InternalList(w)[i + 1];

#ifdef USE_CUM_HEIGHT
	List_InternalList(w)[i]->CumHeight -=
	    height + 2 * Prim_HighlightThickness(w) + List_ItemSpacing(w);
#endif
    }

    /* Handle case where item is selected */
    if (List_LastItem(w) == position)
    {
	List_LastItem(w) = 0;
    }

    for (is_selected = False, i = 0; i < List_SelectedItemCount(w); i++)
    {
	/* If we haven't found the item yet, test for it, else shuffle */
	if (!is_selected)
	{
	    if (List_SelectedIndices(w)[i] == position)
	    {
		List_SelectedItemCount(w)--;
		is_selected = True;
	    }
	}
	else
	{
	    List_SelectedIndices(w)[i] = List_SelectedIndices(w)[i + 1];
	    List_SelectedItems(w)[i] = List_SelectedItems(w)[i + 1];
	}
    }

    /*
     * Realloc items.  I could optimize this by not reallocating unless the
     * list needs to be larger. 
     */
    --List_ItemCount(w);
    _XmListReallocItems(w);
    _XmListReallocSelectedItems(w);

    /* Update MaxWidth/MaxItemHeight */
    if (List_ItemCount(w))
    {
	max_width_so_far = 0;
	max_height_so_far = 0;

	for (i = 0; i < List_ItemCount(w); i++)
	{
	    if (List_InternalList(w)[i]->height > max_height_so_far)
	    {
		max_height_so_far = List_InternalList(w)[i]->height;
	    }
	    if (List_InternalList(w)[i]->width > max_width_so_far)
	    {
		max_width_so_far = List_InternalList(w)[i]->width;
	    }
	}
    }
    else
    {
	/*
	 * No items left in the list.
	 */
	XmString x = XmStringCreateSimple(" ");
	XmStringExtent(List_Font(w), x, &max_width_so_far, &max_height_so_far);
	XmStringFree(x);
	max_width_so_far = 8 * max_height_so_far;
    }

	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListDeletePos(%i): MaxItemWidth: %d\n",
			      __LINE__, max_width_so_far));
    List_MaxWidth(w) = max_width_so_far;
    List_MaxItemHeight(w) = max_height_so_far;

    if (List_ItemCount(w) &&
	List_TopPosition(w) + List_VisibleItemCount(w) - 1 > List_ItemCount(w))
    {
	List_TopPosition(w) = 1;
    }

    _XmListInitScrollBars(w, True, True);
}

/* Deletes an item with value <item>, if one exists */
static Boolean
_XmListDeleteItem(Widget w, XmString item)
{
    int i;

#ifndef USE_SEPARATE_ITEMS_LIST
    _XmString _item = _XmStringCreate(item);
#endif

    for (i = 0; i < List_ItemCount(w); i++)
    {
#ifdef USE_SEPARATE_ITEMS_LIST
	if (XmStringCompare(item, List_Items(w)[i]))
#else
	if (_XmStringCompare(_item, List_InternalList(w)[i]->name))
#endif
	{
	    _XmListDeletePos(w, i + 1);
	    return True;
	}
    }

    return False;
}

/*
 * Clones the items and InternalList instance variable for the widget
 * and reallocates the selected items arrays. 
 */
static void
_XmListInstallItems(Widget w)
{
    Dimension max_height_so_far = 0, max_width_so_far = 0;
    Dimension height;
    XmString x;

    if (Prim_Highlighted(w))
	_XmListUnhighlight(w);

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListInstallItems: entering\n"));

    /*
     *  This is probably a kluge, but it seems to work.
     */
    x = XmStringCreateSimple("W");
    XmStringExtent(List_Font(w), x, &List_CharWidth(w), &height);

    /* this looks like the value M*tif uses */
    List_CharWidth(w) = 10;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListInstallItems: CharWidth = %d\n",
		      List_CharWidth(w)));

    if (List_ItemCount(w) != 0)
    {
	int i;

#ifdef USE_SEPARATE_ITEMS_LIST
	XmString *new_items, *list_items = List_Items(w);
#else
	_XmString *new_items, *list_items = List_Items(w);
#endif
	ElementPtr *new_elements;

#ifdef USE_CUM_HEIGHT
	Dimension cum_height = Prim_ShadowThickness(w);
#endif

#ifdef USE_SEPARATE_ITEMS_LIST
	List_Items(w) = NULL;
#endif
	List_InternalList(w) = NULL;
	List_SelectedIndices(w) = NULL;

	_XmListReallocItems(w);
	_XmListReallocSelectedItems(w);

	new_items = List_Items(w);
	new_elements = List_InternalList(w);

	for (i = 0; i < List_ItemCount(w); i++)
	{
	    new_items[i] = XmStringCopy(list_items[i]);

	    new_elements[i] = (ElementPtr)XtMalloc(sizeof(Element));

	    new_elements[i]->name = _XmStringCreate(new_items[i]);
	    new_elements[i]->selected =
		new_elements[i]->last_selected =
		new_elements[i]->LastTimeDrawn = False;

	    new_elements[i]->NumLines = XmStringLineCount(new_items[i]);
	    new_elements[i]->length = XmStringLength(new_items[i]);

	    XmStringExtent(List_Font(w), new_items[i],
			   &new_elements[i]->width, &new_elements[i]->height);

#ifdef USE_CUM_HEIGHT
	    cum_height += (new_elements[i]->height
			   + 2 * Prim_HighlightThickness(w)
			   + List_ItemSpacing(w));

	    new_elements[i]->CumHeight = cum_height;
#endif
	    if (max_height_so_far < new_elements[i]->height)
		max_height_so_far = new_elements[i]->height;

	    if (max_width_so_far < new_elements[i]->width)
		max_width_so_far = new_elements[i]->width;
	}

	List_SelectedItemCount(w) = 0;

    }
    else
    {
	/* rws 14 Nov 1997
	   Why was this height * 8 ????
	   This causes the page list in mgv to be 112 when it wants to
	   be ~20.
	max_width_so_far = height * 8;
	*/
        max_width_so_far = List_CharWidth(w);
	max_height_so_far = height;

#ifdef USE_SEPARATE_ITEMS_LIST
	List_Items(w) = NULL;
#endif
	List_InternalList(w) = NULL;
	List_SelectedIndices(w) = NULL;
	List_SelectedItems(w) = NULL;
	List_SelectedItemCount(w) = 0;
    }
    XmStringFree(x);
    List_MaxItemHeight(w) = max_height_so_far;
	    DEBUGOUT(XdbDebug(__FILE__, w,
			      "_XmListInstallItems(%i): MaxItemWidth: %d\n",
			      __LINE__, max_width_so_far));
    List_MaxWidth(w) = max_width_so_far;

    _XmListInitScrollBars(w, True, True);

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListInstallItems: exiting\n"));
}

/*******************************/
/* Item selection/deselection */
/*****************************/

/* Selects the item at position <position> */
static void
_XmListSelectPos(Widget w, int position)
{
    int i;

    if (position < 0 || position > List_ItemCount(w))
    {
	return;
    }

    if (!position)
    {
	position = List_ItemCount(w);
    }

    if (List_InternalList(w)[position - 1]->selected == True)
    {
	return;
    }

    List_InternalList(w)[position - 1]->selected = True;
    List_InternalList(w)[position - 1]->LastTimeDrawn = False;

    if (List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	List_SelectedItems(w)[0] = List_Items(w)[position - 1];
	List_SelectedIndices(w)[0] = position;
	List_SelectedItemCount(w) = 1;
    }
    else
    {
	for (i = 0; i < List_SelectedItemCount(w); i++)
	{
	    if (position == List_SelectedIndices(w)[i])
	    {
		/* it's already in the list.  Don't add it again */
		return;
	    }
	}

	/* can't select any more items? */
	if (List_SelectedItemCount(w) == List_ItemCount(w))
	{
	    return;
	}

	List_SelectedItems(w)[List_SelectedItemCount(w)] =
	    List_Items(w)[position - 1];
	List_SelectedIndices(w)[List_SelectedItemCount(w)] = position;
	List_SelectedItemCount(w)++;
    }

    List_LastItem(w) = position;
}

/* Selects all unselected items */
static void
_XmListSelectAll(Widget w)
{
    int pos;

    for (pos = 1; pos <= List_ItemCount(w); pos++)
    {
	_XmListSelectPos(w, pos);
    }
}

static void
_XmListSelectPosIfMatch(Widget w, int position)
{
    int i;

    /* position == 0 means last position */
    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    /* do nothing if already selected */
    if (List_InternalList(w)[position - 1]->selected)
    {
	return;
    }

    /* if the item at the specified position matches any of 
     * the items in XmNselectedItems, then select the item at
     * the specified position */
    for (i = 0; i < List_SelectedItemCount(w); ++i)
    {
	if (XmStringCompare(List_Items(w)[position - 1],
			    List_SelectedItems(w)[i]))
	{
	    _XmListSelectPos(w, position);

	    break;
	}
    }
}

/* Deselects the item at position <position> */
static Boolean
_XmListDeselectPos(Widget w,
		   int position)
{
    int i, j;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListDeselectPos() last_item = %d\n",
		      List_LastItem(w)));

    if (position < 0 || position > List_ItemCount(w))
    {
	return False;
    }

    if (!position)
    {
	position = List_ItemCount(w);
    }

    if (List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	if (List_LastItem(w) == position)
	{
	    List_InternalList(w)[position - 1]->selected = False;
	    List_InternalList(w)[position - 1]->LastTimeDrawn = False;
	    List_SelectedItemCount(w) = 0;
	    List_LastItem(w) = 0;

	    return True;
	}
    }
    /* XmMULTIPLE_SELECT or XmEXTENDED_SELECT */
    else
    {
	if (List_SelectedItemCount(w) == 0)
	{
	    return False;
	}

	List_InternalList(w)[position - 1]->selected = False;
	List_InternalList(w)[position - 1]->LastTimeDrawn = False;
	if (List_LastItem(w) == position)
	{
	    List_LastItem(w) = 0;
	}

	for (i = 0; i < List_SelectedItemCount(w); i++)
	{
	    if (position == List_SelectedIndices(w)[i])
	    {
		for (j = i; j < List_SelectedItemCount(w) - 1; j++)
		    List_SelectedIndices(w)[j] = List_SelectedIndices(w)[j + 1];

		List_SelectedItemCount(w)--;
		break;
	    }
	}

    }
    return True;
}

/* Deselects all selected items */
static void
_XmListDeselectAll(Widget w)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListDeselectAll()\n"));

    for (i = 0; i < List_ItemCount(w); i++)
    {
	if (List_InternalList(w)[i]->selected)
	{
	    List_InternalList(w)[i]->selected = False;
	    List_InternalList(w)[i]->LastTimeDrawn = False;
	}
    }

    /* should I deallocate the array here? */
    List_SelectedItemCount(w) = 0;
    List_LastItem(w) = 0;
}

/* Toggles the selection state of position <position> */
static void
_XmListTogglePos(Widget w, int position)
{
    if (List_InternalList(w)[position - 1]->selected)
    {
	_XmListDeselectPos(w, position);
    }
    else
    {
	_XmListSelectPos(w, position);
    }
}

static void
_XmListInvokeCallbacks(Widget w,
		       XEvent *event,
		       Boolean default_action)
{
    int *selected_item_positions = NULL;
    XmString *selected_items = NULL;
    XmListCallbackStruct call_data;
    XtCallbackList callbacks = NULL;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListInvokeCallbacks(%d)\n", default_action));

    /* information that is always present in callbacks */
    call_data.event = event;
    if (List_LastItem(w) > 0)
    {
	call_data.item = List_Items(w)[List_LastItem(w) - 1];
	call_data.item_position = List_LastItem(w);
	call_data.item_length = XmStringLength(call_data.item);
    }
    else
    {
	call_data.item = NULL;
	call_data.item_position = 0;
	call_data.item_length = 0;
    }

    /* defaultActionCallback */
    if (default_action && List_DefaultCallback(w) != NULL)
    {
	call_data.reason = XmCR_DEFAULT_ACTION;
	callbacks = List_DefaultCallback(w);
    }
    /* one of the selection policy callbacks */
    else
    {
	switch (List_SelectionPolicy(w))
	{
	case XmBROWSE_SELECT:
	    call_data.reason = XmCR_BROWSE_SELECT;
	    callbacks = List_BrowseCallback(w);
	    break;

	case XmSINGLE_SELECT:
	    call_data.reason = XmCR_SINGLE_SELECT;
	    callbacks = List_SingleCallback(w);
	    break;

	case XmMULTIPLE_SELECT:
	    call_data.reason = XmCR_MULTIPLE_SELECT;
	    callbacks = List_MultipleCallback(w);
	    break;

	case XmEXTENDED_SELECT:
	    call_data.reason = XmCR_EXTENDED_SELECT;
	    callbacks = List_ExtendCallback(w);
	    break;
	}
    }

    if (callbacks == NULL)
    {
	return;
    }

    if (call_data.reason == XmCR_EXTENDED_SELECT ||
	call_data.reason == XmCR_MULTIPLE_SELECT)
    {
	int i;

	selected_item_positions =
	    (int *)XtMalloc(List_SelectedItemCount(w) * sizeof(int));
	selected_items = (XmString *)XtMalloc(List_SelectedItemCount(w) *
					      sizeof(XmString));

	for (i = 0; i < List_SelectedItemCount(w); i++)
	    selected_items[i] = XmStringCopy(List_SelectedItems(w)[i]);

	bcopy(List_SelectedIndices(w),
	      selected_item_positions,
	      List_SelectedItemCount(w) * sizeof(int));

	call_data.selected_items = selected_items;
	call_data.selected_item_positions = selected_item_positions;
	call_data.selected_item_count = List_SelectedItemCount(w);

	if (call_data.reason == XmCR_EXTENDED_SELECT)
	{
	    call_data.selection_type = List_SelectionType(w);
	}
    }

    XtCallCallbackList(w, callbacks, (XtPointer)&call_data);

    if (call_data.reason == XmCR_EXTENDED_SELECT ||
	call_data.reason == XmCR_MULTIPLE_SELECT)
    {
	int i;

	for (i = 0; i < List_SelectedItemCount(w); i++)
	{
	    XmStringFree(selected_items[i]);
	}

	XtFree((XtPointer)selected_items);

	XtFree((XtPointer)selected_item_positions);
    }
}

/**********************/
/* Drawing functions */
/********************/
#ifdef TEST
static void
_XmListErasePos(Widget w, int pos)
{
    int x;
    int y;
    XRectangle clip_rect;

    Dimension fill_width = (XtWidth(w) - 2 * (Prim_ShadowThickness(w) +
					      List_MarginWidth(w) +
					      Prim_HighlightThickness(w) + 1));

    GC myGC = XtSensitive(w) ? List_NormalGC(w) : List_InsensitiveGC(w);

    DEBUGOUT(XdbDebug(__FILE__, w, "_XmListErasePos()\n"));

    if (!XtIsRealized(w))
    {
	return;
    }

    x = (List_MarginWidth(w) + Prim_ShadowThickness(w) +
	 Prim_HighlightThickness(w) + 1);	/* why is this + 1??? */
    y = (List_MarginHeight(w) + Prim_ShadowThickness(w) +
	 Prim_HighlightThickness(w) + 1);	/* why is this + 1??? */

    clip_rect.x = (Position)x;
    clip_rect.y = (Position)y;
    clip_rect.width = (Dimension)(fill_width);
    clip_rect.height = (Dimension)List_MaxItemHeight(w);

    XFillRectangle(XtDisplay(w), XtWindow(w),
		   (List_InternalList(w)[pos]->selected
		    ? List_NormalGC(w)
		    : List_InverseGC(w)),
		   x, y, fill_width,
		   List_MaxItemHeight(w));
}
#endif

/*
 * set the redraw_all_visible to True if all the items visible should be
 * redrawn.  If you're changing just one item, set this to false,
 * but make sure you set the LastTimeDrawn in that item's InternalList entry
 * to False
 */
static void
_XmListRedraw(Widget w,
	      Boolean redraw_all_visible)
{
    Position x, y;
    int i;
    GC myGC = XtSensitive(w) ? List_NormalGC(w) : List_InsensitiveGC(w);
    Dimension fill_width = (XtWidth(w) - 2 * (Prim_ShadowThickness(w) +
					      List_MarginWidth(w) +
					      Prim_HighlightThickness(w) + 1));

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListRedraw(): width = %d, visible = %d\n",
		      (int)XtWidth(w), List_VisibleItemCount(w)));

    if (!XtIsRealized(w))
    {
	return;
    }

    if (redraw_all_visible)
    {
	XClearWindow(XtDisplay(w), XtWindow(w));
    }

    x = (List_MarginWidth(w) + Prim_ShadowThickness(w) +
	 Prim_HighlightThickness(w) + 1);	/* why is this + 1??? */
    y = (List_MarginHeight(w) + Prim_ShadowThickness(w) +
	 Prim_HighlightThickness(w) + 1);	/* why is this + 1??? */

    for (i = List_TopPosition(w) - 1;
	 (i < List_ItemCount(w)) &&
	 (i < List_VisibleItemCount(w) + List_TopPosition(w) - 1);
	 i++)
    {

	if (i < 0)
	{
	    continue;
	}

	if (List_InternalList(w)[i]->LastTimeDrawn == False ||
	    redraw_all_visible == True)
	{
	    XRectangle clip_rect;

	    DEBUGOUT(XdbDebug(__FILE__, w,
			 "  XmListRedraw() redrawing item %d...yes\n", i + 1));

	    /* we don't want to continually redraw this item... */
	    List_InternalList(w)[i]->LastTimeDrawn = True;

	    clip_rect.x = (Position)x;
	    clip_rect.y = (Position)y;
	    clip_rect.width = (Dimension)(fill_width);
	    clip_rect.height = (Dimension)List_MaxItemHeight(w);


	    XFillRectangle(XtDisplay(w), XtWindow(w),
			   (List_InternalList(w)[i]->selected
			    ? List_NormalGC(w) : List_InverseGC(w)),
			   x, y,
			   fill_width,
			   List_MaxItemHeight(w));

	    if (List_InternalList(w)[i]->selected)
	    {
#ifdef JONS_CLIP_MASK_KLUDGE
		XSetClipRectangles(XtDisplay(w), List_InverseGC(w),
				   0, 0, &clip_rect, 1, Unsorted);
#endif
		_XmStringDraw(XtDisplay(w),
			      XtWindow(w),
			      List_Font(w),
			      List_InternalList(w)[i]->name,
			      List_InverseGC(w),
			      x - List_XOrigin(w),
			      y + (List_MaxItemHeight(w) -
				   List_InternalList(w)[i]->height) / 2,
			      fill_width,
			      XmALIGNMENT_BEGINNING,
			      List_StrDir(w),
			      &clip_rect);

#ifdef JONS_CLIP_MASK_KLUDGE
		/* remove clip mask */
		XSetClipMask(XtDisplay(w), List_InverseGC(w), None);
#endif
	    }

	    if (!List_InternalList(w)[i]->selected || !XtSensitive(w))
	    {
#ifdef JONS_CLIP_MASK_KLUDGE
		XSetClipRectangles(XtDisplay(w), myGC,
				   0, 0, &clip_rect, 1, Unsorted);
#endif
		_XmStringDraw(XtDisplay(w),
			      XtWindow(w),
			      List_Font(w),
			      List_InternalList(w)[i]->name,
			      myGC,
			      x - List_XOrigin(w),
			      y + (List_MaxItemHeight(w) -
				   List_InternalList(w)[i]->height) / 2,
			      fill_width,
			      XmALIGNMENT_BEGINNING,
			      List_StrDir(w),
			      &clip_rect);

#ifdef JONS_CLIP_MASK_KLUDGE
		/* remove clip mask */
		XSetClipMask(XtDisplay(w), myGC, None);
#endif
	    }
	}
	else
	{
	    DEBUGOUT(XdbDebug(__FILE__, w,
			  "  XmListRedraw() redrawing item %d...no\n", i + 1));
	}

	y += (List_MaxItemHeight(w) + Prim_HighlightThickness(w) + 1 +
	      List_ItemSpacing(w));
    }

    _XmDrawShadows(XtDisplay(w),
		   XtWindow(w),
		   Prim_TopShadowGC(w),
		   Prim_BottomShadowGC(w),
		   0, 0,
		   XtWidth(w),
		   XtHeight(w),
		   Prim_ShadowThickness(w), XmSHADOW_IN);

    if (Prim_Highlighted(w))
    {
	_XmListHighlight(w);
    }
}

/******************/
/* Miscellaneous */
/****************/

/* Set the current cursor position. Position must be visible */
static void
_XmListSetCursorPos(Widget w, int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetCursorPos(): position: %d, HL: %d\n",
		      position, List_LastHLItem(w)));

    /*
     * return if cursor position is out of visible range
     */
    if (position < List_TopPosition(w) ||
	position > List_TopPosition(w) + List_VisibleItemCount(w) - 1)
    {
	return;
    }

    if (List_LastHLItem(w))
    {
	List_InternalList(w)[List_LastHLItem(w) - 1]->LastTimeDrawn = False;
	if (Prim_Highlighted(w))
	{
	    _XmListUnhighlight(w);
	}
    }

    List_LastHLItem(w) = position;
    List_InternalList(w)[position - 1]->LastTimeDrawn = False;
}



/*
 * Set which item is displayed at the top of the list
 * NOTE: this function should not alter the last highlighted
 * item!
 */
static void
_XmListSetTopPos(Widget w, int position, Boolean *redraw_all)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetTopPos(): position: %d\n", position));

    *redraw_all = False;

    if (List_TopPosition(w) != position)
    {
	if (Prim_Highlighted(w))
	{
	    _XmListUnhighlight(w);
	}

	List_TopPosition(w) = position;
#ifdef OLD_22MAY
	if (List_LastHLItem(w) < List_TopPosition(w))
	{
	    _XmListSetCursorPos(w, List_TopPosition(w));
	}
	else if (List_LastHLItem(w) > List_TopPosition(w) +
		 List_VisibleItemCount(w) - 1)
	{
	    _XmListSetCursorPos(w, List_TopPosition(w) +
				List_VisibleItemCount(w) - 1);
	}
#endif
	*redraw_all = True;

	_XmListUpdateVertScrollBar(w);
    }
}

/* Restores the old selection for any items in the current select range */
static void
_XmListRestoreSelectRange(Widget w)
{
    int pos, direction, last_pos;

    /* Restore items from the anchor point to the old position */
    last_pos = List_LastItem(w);
    direction = (last_pos > List_StartItem(w)) ? 1 : -1;

    for (pos = List_StartItem(w) + direction;
#ifdef	DO_SANITY
	 pos > 0 &&
#endif
	 pos != last_pos + direction;
	 pos += direction)
    {
	DEBUGOUT(XdbDebug(__FILE__, w,
			  "In for loop. pos: %d, direction: %d\n",
			  pos, direction));
	if (List_InternalList(w)[pos - 1]->saved_select)
	{
	    _XmListSelectPos(w, pos);
	}
	else
	{
	    _XmListDeselectPos(w, pos);
	}
    }
}

/* Changes the current selection range from anchor->List_LastItem(w) to
 * anchor->new-position */
static void
_XmListSetSelectRange(Widget w, int new_position)
{
    int pos, direction;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "_XmListSetSelectRange() LastItem: %d, "
		      "position: %d, anchor: %d\n",
		      List_LastItem(w), new_position,
		      List_StartItem(w)));

    _XmListRestoreSelectRange(w);

    /* Save items from the anchor point to here and set their 
     * selection state to the same as the anchor */
    direction = (new_position > List_StartItem(w)) ? 1 : -1;
    for (pos = List_StartItem(w) + direction;
	 pos != new_position + direction;
	 pos += direction)
    {
	List_InternalList(w)[pos - 1]->saved_select =
	    List_InternalList(w)[pos - 1]->selected;

	if (List_InternalList(w)[List_StartItem(w) - 1]->selected)
	{
	    _XmListSelectPos(w, pos);
	}
	else
	{
	    _XmListDeselectPos(w, pos);
	}
    }

    /* Eeek!  We have to do this so that the focus will move when
     * the mouse button is released, but if the anchor item is
     * unselected then LastItem will not point to the last selected
     * item, as it should.
     */
    List_LastItem(w) = new_position;
}

/***********************/
/* internal callbacks */
/*********************/

static void
_XmListHorizontalScrollBarCallback(Widget w,
				   XtPointer client_data,
				   XtPointer call_data)

{
    XmScrollBarCallbackStruct *cbs = (XmScrollBarCallbackStruct *)call_data;
    Widget list = (Widget)client_data;

    List_Horigin(list) = List_XOrigin(list) = cbs->value;

    _XmListRedraw(list, True);
}

static void
_XmListVerticalScrollBarCallback(Widget w,
				 XtPointer client_data,
				 XtPointer call_data)
{
    Boolean redraw_all = False;
    XmScrollBarCallbackStruct *cbs = (XmScrollBarCallbackStruct *)call_data;
    Widget list = (Widget)client_data;

    /*  cbs->value must be incremented because scrollbar values
     * are 0..ItemCount */
    _XmListSetTopPos(list, cbs->value + 1, &redraw_all);
    _XmListRedraw(list, redraw_all);
}

/*******************/
/* widget methods */
/*****************/

static void
class_initialize()
{
    _XmListCoreClassExtRec.record_type = XmQmotif;
}

static void
class_part_initialize(WidgetClass widget_class)
{
    _XmFastSubclassInit(widget_class, XmLIST_BIT);
}

static void
destroy(Widget w)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "Detroy()\n"));

    _XmListFreeItems(w);
#if 0
    /* This crashes xmbdfed */
    _XmListFreeSelectedItems(w);
#endif
#if 0
    XtFree((XtPointer)List_SelectedItems(w));	/* moved out of _XmListFreeItems */
#endif

    XtReleaseGC(w, List_NormalGC(w));
    XtReleaseGC(w, List_HighlightGC(w));

    if (List_Mom(w) && !CoreBeingDestroyed(List_Mom(w)))
    {
	XtDestroyWidget((Widget)List_Mom(w));
    }
}

static void
resize(Widget w)
{
    int new_top;
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "resize() (%d, %d)\n", XtWidth(w), XtHeight(w)));

    if (Prim_Highlighted(w))
    {
	_XmListUnhighlight(w);
    }

    _XmListRecalcItems(w, &redraw_all);

    if (List_TopPosition(w) > 1 &&
	List_TopPosition(w) > List_ItemCount(w) - List_VisibleItemCount(w) + 1)
    {
	new_top = List_ItemCount(w) - List_VisibleItemCount(w) + 1;
	if (new_top < 1)
	{
	    new_top = 1;
	}

	DEBUGOUT(XdbDebug(__FILE__, w,
			  "TopPos(old,new) = %d, %d\n",
			  List_TopPosition(w), new_top));

	_XmListSetTopPos(w, new_top, &redraw_all);
    }

    _XmListInitScrollBars(w, True, True);

#ifdef OLD_22MAY
    if (List_LastHLItem(w) < List_TopPosition(w))
    {
	_XmListSetCursorPos(w, List_TopPosition(w));
    }
    else if (List_LastHLItem(w) > List_TopPosition(w) +
	     List_VisibleItemCount(w) - 1)
    {
	_XmListSetCursorPos(w, List_TopPosition(w) +
			    List_VisibleItemCount(w) - 1);
    }
#endif

    _XmListRedraw(w, True);
}

static void
expose(Widget w, XEvent *event, Region region)
{
    XmListWidgetClass wc = (XmListWidgetClass)XtClass(w);

    DEBUGOUT(XdbDebug(__FILE__, w, "expose()\n"));

    _XmListRedraw(w, True);
    if (Prim_Highlighted(w))
    {
	(*wc->primitive_class.border_highlight) (w);
    }
    else
    {
	(*wc->primitive_class.border_unhighlight) (w);
    }
#undef superclass
}

static void
CreateNormalGC(Widget w)
{
    XGCValues values;

    values.foreground = Prim_Foreground(w);
    values.background = XtBackground(w);

    List_NormalGC(w) = XtGetGC(w, GCForeground | GCBackground, &values);
}

static void
CreateHighlightGC(Widget w)
{
    unsigned long mask = GCForeground | GCBackground;
    XGCValues values;

    values.foreground = Prim_HighlightColor(w);
    values.background = XtBackground(w);

    if (List_AddMode(w))
    {
#if 0
/* URK!  DashTile isn't initialized! */
	mask |= GCTile | GCFillStyle;

	values.tile = List_DashTile(w);
	values.fill_style = FillTiled;
#endif
    }

    List_HighlightGC(w) = XtGetGC(w, mask, &values);
}

static void
CreateInsensitiveGC(Widget w)
{
    XGCValues values;
    XtGCMask mask;

    mask = GCForeground | GCBackground | GCFillStyle | GCFunction |
	GCStipple | GCPlaneMask | GCSubwindowMode |
	GCGraphicsExposures | GCTileStipXOrigin | GCTileStipYOrigin;

    values.function = GXcopy;
    values.plane_mask = -1;
    values.subwindow_mode = ClipByChildren;
    values.graphics_exposures = False;
    values.foreground = Prim_Foreground(w);
    values.background = XtBackground(w);
    values.fill_style = FillStippled;
    values.ts_x_origin = values.ts_y_origin = 0;
    values.stipple = XmGetPixmapByDepth(XtScreen(w),
					XmODD_STIPPLE_IMAGE,
					WhitePixelOfScreen(XtScreen(w)),
					BlackPixelOfScreen(XtScreen(w)),
					1);

    List_InsensitiveGC(w) = XtGetGC(w, mask, &values);
}

static void
CreateInverseGC(Widget w)
{
    XGCValues values;

    values.foreground = XtBackground(w);
    values.background = Prim_Foreground(w);

    List_InverseGC(w) = XtGetGC(w, GCForeground | GCBackground, &values);
}

static void
initialize(Widget request, Widget new_w,
	   ArgList args, Cardinal *num_args)
{
    XtTranslations trans = XtParseTranslationTable(_XmList_ListXlations2);
    XtOverrideTranslations(new_w, trans);

    DEBUGOUT(XdbDebug(__FILE__, new_w, "initialize() Visible: %d\n",
		      List_VisibleItemCount(new_w)));
    DEBUGOUT(XdbDebug(__FILE__, new_w,
		      "initialize: %i args Visible: %d\n"
		      "\trequest X %5i Y %5i W %5i H %5i\n"
		      "\t  new_w X %5i Y %5i W %5i H %5i\n",
		      *num_args, List_VisibleItemCount(new_w),
		      XtX(request), XtY(request),
		      XtWidth(request), XtHeight(request),
		      XtX(new_w), XtY(new_w),
		      XtWidth(new_w), XtHeight(new_w)));
    DEBUGOUT(XdbPrintArgList(__FILE__, new_w, args, *num_args, False));


    if (List_Font(new_w) == NULL ||
	List_Font(new_w) == (XmFontList)XmUNSPECIFIED)
    {
	List_Font(new_w) = _XmGetDefaultFontList(new_w, XmTEXT_FONTLIST);
    }
    /* user specified font? */
    else
    {
	List_Font(new_w) = XmFontListCopy(List_Font(new_w));
    }


    List_AddMode(new_w) = False;

    if (List_ItemCount(new_w) == XmUNSPECIFIED)
    {
	List_ItemCount(new_w) = 1;
    }

    List_StartItem(new_w) = 0;
    List_LastItem(new_w) = 0;

    List_LastHLItem(new_w) = 0;
    List_DragID(new_w) = (XtIntervalId)NULL;

    if (List_VisibleItemCount(new_w) == 0)
    {
	List_VisibleItemCount(new_w) = 1;
    }

    /* So InstallItems doesn't try to do any scrollbar things */
    List_Mom(new_w) = NULL;
    List_FromSetSB(new_w) = False;
    List_FromSetNewSize(new_w) = False;

    /* Initialise Items, InternalList, SelectedItems, SelectedIndices,
     * SelectedItemCount, MaxWidth, MaxItemHeight */
    _XmListInstallItems(new_w);

    if (List_TopPosition(new_w) < 1 ||
	List_TopPosition(new_w) > List_ItemCount(new_w))
    {
	List_TopPosition(new_w) = 1;
    }

    List_LastHLItem(new_w) = List_TopPosition(new_w);

    List_XOrigin(new_w) = 0;	/* initialize x coordinate */
    List_Horigin(new_w) = 0;
    List_Hmin(new_w) = 0;
    List_Vorigin(new_w) = 0;
    List_Vmin(new_w) = 0;

    CreateNormalGC(new_w);
    CreateInsensitiveGC(new_w);
    CreateInverseGC(new_w);
    CreateHighlightGC(new_w);

    _XmListCalculateInitialGeometry(new_w, request);

    if (XmIsScrolledWindow(XtParent(new_w)))
    {
	List_Mom(new_w) = (XmScrolledWindowWidget)XtParent(new_w);
    }
    else
    {
	List_Mom(new_w) = NULL;
    }

    /* Below this point calls to parent methods, which may invoke callbacks
     * occur, so we have to have everything else sorted by here */
    if (List_IsScrolledList(new_w))
    {
	char *name = XtMalloc(strlen(XtName(new_w)) + 4);

	strcpy(name, XtName(new_w));
	strcat(name, "HSB");
	List_HSB(new_w) =
	    (XmScrollBarWidget)XtVaCreateWidget(name,
						xmScrollBarWidgetClass,
						(Widget)List_Mom(new_w),
						XmNorientation, XmHORIZONTAL,
						NULL);

	XtAddCallback((Widget)List_HSB(new_w), XmNdecrementCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNdragCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNincrementCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNpageDecrementCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNpageIncrementCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNtoBottomCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNtoTopCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_HSB(new_w), XmNvalueChangedCallback,
		      _XmListHorizontalScrollBarCallback,
		      (XtPointer)new_w);

	strcpy(name, XtName(new_w));
	strcat(name, "VSB");
	List_VSB(new_w) =
	    (XmScrollBarWidget)XtVaCreateWidget(name,
						xmScrollBarWidgetClass,
						XtParent(new_w),
						NULL);

	if (List_SBDisplayPolicy(new_w) == XmSTATIC ||
	    (List_SBDisplayPolicy(new_w) == XmAS_NEEDED &&
	     List_ItemCount(new_w) > List_VisibleItemCount(new_w)))
	{
	    XtManageChild((Widget)List_VSB(new_w));
	}
	else
	{
	    DEBUGOUT(XdbDebug(__FILE__, new_w, "  VSB not managed\n"));
	}

	XtAddCallback((Widget)List_VSB(new_w), XmNdecrementCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNdragCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNincrementCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNpageDecrementCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNpageIncrementCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNtoBottomCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNtoTopCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);
	XtAddCallback((Widget)List_VSB(new_w), XmNvalueChangedCallback,
		      _XmListVerticalScrollBarCallback,
		      (XtPointer)new_w);

	XmScrolledWindowSetAreas((Widget)List_Mom(new_w),
				 (Widget)List_HSB(new_w),
				 (Widget)List_VSB(new_w), new_w);

	/*
	 * XtVaSetValues((Widget)List_Mom(new_w),
	 * XmNscrollingPolicy, XmAPPLICATION_DEFINED,
	 * XmNvisualPolicy, XmVARIABLE,
	 * NULL);
	 */

	if (XtIsManaged(List_VSB(new_w)))
	{
	    DEBUGOUT(XdbDebug(__FILE__, new_w, "  VSB is now managed\n"));
	}

	_XmListInitScrollBars(new_w, True, True);

	XtFree(name);
    }

    /* This is needed to initialize double-click detection */
    List_DownCount(new_w) = 0;
    List_DownTime(new_w) = 0;

    if (List_ClickInterval(new_w) == XmUNSPECIFIED)
    {
	List_ClickInterval(new_w) = XtGetMultiClickTime(XtDisplay(new_w));
    }

    /*
     * I'd like to have XmListCalculateInitialGeometry() here
     */
}

static Boolean
set_values(Widget old, Widget request, Widget new_w,
	   ArgList args, Cardinal *num_args)
{
    Boolean need_refresh = False, need_newgeo = False;
    int i;
    XmStringTable new_selected_items;
    int new_selected_item_count;

    DEBUGOUT(XdbDebug(__FILE__, new_w,
		      "set_values: %i args\n"
		      "\t    old X %5i Y %5i W %5i H %5i\n"
		      "\trequest X %5i Y %5i W %5i H %5i\n"
		      "\t  new_w X %5i Y %5i W %5i H %5i\n",
		      *num_args,
		      XtX(old), XtY(old),
		      XtWidth(old), XtHeight(old),
		      XtX(request), XtY(request),
		      XtWidth(request), XtHeight(request),
		      XtX(new_w), XtY(new_w),
		      XtWidth(new_w), XtHeight(new_w)));
    DEBUGOUT(XdbPrintArgList(__FILE__, new_w, args, *num_args, False));

    if (List_SizePolicy(old) != List_SizePolicy(new_w))
    {
	_XmWarning(new_w,
		   "Cannot change XmNlistSizePolicy after initialization.\n");

	List_SizePolicy(new_w) = List_SizePolicy(old);
    }

    if (List_Font(old) != List_Font(new_w))
    {
	XmFontListFree(List_Font(old));

	List_Font(new_w) = XmFontListCopy(List_Font(request));

	need_newgeo = True;
	need_refresh = True;
    }

    /* The list of selected items needs to be saved here, because
     * InstallItems will trample on it */
    new_selected_items = List_SelectedItems(new_w);
    new_selected_item_count = List_SelectedItemCount(new_w);

    if (List_ItemCount(old) != List_ItemCount(new_w) &&
	List_Items(old) == List_Items(new_w))
    {
	List_ItemCount(new_w) = List_ItemCount(old);
	List_Items(new_w) = List_Items(old);

	_XmWarning(new_w,
	   "XmNitemCount and XmNitems must be set by the same XtSetValues.\n");
    }
    else if (List_Items(old) != List_Items(new_w))
    {
	List_SelectedItems(new_w) = NULL;
	List_SelectedItemCount(new_w) = 0;

	/* new stuff */
	List_TopPosition(new_w) = 1;
	/* JKF: This was 0. Had to change this to 1 */

	_XmListInstallItems(new_w);

	/*_XmListFreeItems(old);*/

	need_newgeo = True;
	need_refresh = True;
    }

    if (List_MarginHeight(old) != List_MarginHeight(new_w) ||
	List_MarginWidth(old) != List_MarginWidth(new_w) ||
	List_ItemSpacing(old) != List_ItemSpacing(new_w) ||
	List_SBDisplayPolicy(old) != List_SBDisplayPolicy(new_w) ||
	List_StrDir(old) != List_StrDir(new_w))
    {
	need_newgeo = True;
	need_refresh = True;
    }

    if (List_VisibleItemCount(old) != List_VisibleItemCount(new_w))
    {
	if (List_VisibleItemCount(new_w) == 0)
	{
	    List_VisibleItemCount(new_w) = 1;
	}

	DEBUGOUT(XdbDebug(__FILE__, new_w,
			  "VisibleItemCount now %d\n",
			  List_VisibleItemCount(new_w)));

	need_newgeo = True;
	need_refresh = True;
    }

    if (List_TopPosition(old) != List_TopPosition(new_w))
    {
	if (List_TopPosition(new_w) < 1 ||
	    (List_TopPosition(new_w) >
	     List_ItemCount(new_w) - List_VisibleItemCount(new_w) + 1))
	{
	    List_TopPosition(new_w) = 1;
	}

	/*List_LastHLItem(new_w) = List_TopPosition(new_w); */
	need_newgeo = True;
	need_refresh = True;
    }

    if (List_SelectedItemCount(old) != new_selected_item_count &&
	List_SelectedItems(old) == new_selected_items)
    {
	List_SelectedItemCount(new_w) = List_SelectedItemCount(old);
	List_SelectedItems(new_w) = List_SelectedItems(old);
	_XmWarning(new_w,
		   "XmNselectedItemCount and XmNselectedItems must be "
		   "set by the same XtSetValues.\n");
    }
    else if (List_SelectedItems(old) != List_SelectedItems(new_w))
    {
	if (List_SelectionPolicy(new_w) == XmBROWSE_SELECT ||
	    List_SelectionPolicy(new_w) == XmSINGLE_SELECT)
	{
	    for (i = 0;
		 i < new_selected_item_count &&
		 List_SelectedItemCount(new_w) == 0;
		 i++)
	    {
		XmListSelectItem(new_w, new_selected_items[i], False);
		/*
		 * When compiled with dmalloc, the line above crashes when
		 * double-clicking on a directory in testXm/filesb/test1. (And
		 * Mosaic, and others).
		 */
	    }
	}
	else
	{
	    List_SelectedItemCount(new_w) = 0;

	    for (i = 0; i < new_selected_item_count; i++)
	    {
		XmListSelectItem(new_w, new_selected_items[i], False);
	    }

	    need_refresh = True;
	}
    }

    if (List_SelectionPolicy(old) != List_SelectionPolicy(new_w))
    {
	switch (List_SelectionPolicy(new_w))
	{
	case XmBROWSE_SELECT:
	case XmEXTENDED_SELECT:
	    List_AddMode(new_w) = False;
	    break;

	case XmSINGLE_SELECT:
	case XmMULTIPLE_SELECT:
	    List_AddMode(new_w) = True;
	    break;

	default:
	    _XmWarning(new_w, "Invalid selectionPolicy.\n");
	}

	/* create the new highlight gc */
	XtReleaseGC(new_w, List_HighlightGC(new_w));
	CreateHighlightGC(new_w);
    }

    if (need_newgeo)
    {
	_XmListSetGeometry(new_w);
    }

    if (List_SelectedItems(old) != List_SelectedItems(new_w))
    {
	XtFree((char *)List_SelectedItems(old));
    }

    return need_refresh;
}


/************/
/* Actions */
/**********/
static void
ListAddMode(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListAddMode action\n"));

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	List_AddMode(w) = !List_AddMode(w);
    }
}

static void
ListBeginData(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginData action\n"));

    List_TopPosition(w) = 1;

    if (!List_AddMode(w))
    {
	_XmListDeselectAll(w);

	_XmListSetTopPos(w, 1, &redraw_all);

	_XmListSelectPos(w, 1);

	_XmListRedraw(w, redraw_all);

	/* send out callbacks */
	List_SelectionType(w) = XmINITIAL;

	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListBeginDataExtend(Widget w, XEvent *event,
		    String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginDataExtend action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmMULTIPLE_SELECT ||
	List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
	{
	    _XmListSetSelectRange(w, 1);
	}

	_XmListSetTopPos(w, 1, &redraw_all);
	_XmListSetCursorPos(w, 1);
	_XmListRedraw(w, redraw_all);

	if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
	{
	    _XmListInvokeCallbacks(w, event, False);
	}
    }
}

static void
ListBeginExtend(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    XButtonEvent *bevent = (XButtonEvent *)event;
    int position;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginExtend action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	XmProcessTraversal(w, XmTRAVERSE_CURRENT);
	position = XmListYToPos(w, bevent->y + List_Vorigin(w));

	if (List_StartItem(w))
	{
	    _XmListSetSelectRange(w, position);
	    _XmListRedraw(w, False);

	    if (List_AutoSelect(w))
	    {
		List_SelectionType(w) = XmMODIFICATION;

		_XmListInvokeCallbacks(w, event, False);
	    }
	}
    }
}

static void
ListBeginLine(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginList action\n"));

    _XmListUpdateHorizScrollBar(w, 0, &redraw_all);
    if (redraw_all)
    {
	_XmListRedraw(w, True);
    }
}

static void
ListBeginSelect(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    XButtonEvent *bevent = (XButtonEvent *)event;
    int position;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginSelect action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    XmProcessTraversal(w, XmTRAVERSE_CURRENT);
    position = XmListYToPos(w, bevent->y + List_Vorigin(w));

    DEBUGOUT(XdbDebug(__FILE__, w, "Selected position %d\n", position));

    switch (List_SelectionPolicy(w))
    {
    case XmBROWSE_SELECT:
	if (List_LastItem(w))
	{
	    _XmListDeselectPos(w, List_LastItem(w));
	}
	_XmListSelectPos(w, position);
	break;

    case XmSINGLE_SELECT:
	if (List_LastItem(w))
	{
	    _XmListDeselectPos(w, List_LastItem(w));
	}
	if (List_LastItem(w) != position)
	{
	    _XmListSelectPos(w, position);
	}
	break;

    case XmMULTIPLE_SELECT:
	_XmListTogglePos(w, position);
	List_LastItem(w) = position;
	break;

    case XmEXTENDED_SELECT:
	_XmListDeselectAll(w);
	_XmListSelectPos(w, position);
	List_StartItem(w) = position;
	break;
    }

    _XmListRedraw(w, False);

    /* Callback only if browse or extended select */
    if ((List_SelectionPolicy(w) == XmBROWSE_SELECT ||
	 List_SelectionPolicy(w) == XmEXTENDED_SELECT) && List_AutoSelect(w))
    {
	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListBeginToggle(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListBeginToggle()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	XButtonEvent *bevent = (XButtonEvent *)event;
	int position;

	XmProcessTraversal(w, XmTRAVERSE_CURRENT);
	position = XmListYToPos(w, bevent->y + List_Vorigin(w));

	if (List_InternalList(w)[position - 1]->selected)
	{
	    _XmListDeselectPos(w, position);
	}
	else
	{
	    _XmListSelectPos(w, position);
	}

	List_StartItem(w) = position;
	_XmListRedraw(w, False);

	if (List_AutoSelect(w))
	{
	    _XmListInvokeCallbacks(w, event, False);
	}
    }
}

#define XmListDRAG_DOWN 0
#define XmListDRAG_UP 1
#define XmListDRAG_TIMEOUT 125

static void
ListDragToPos(Widget w, XEvent *event, int new_pos, Boolean *redraw_all)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListDragToPos() new pos = %d\n", new_pos));

    switch (List_SelectionPolicy(w))
    {
    case XmBROWSE_SELECT:
	{
	    _XmListDeselectPos(w, List_LastItem(w));
	    _XmListSelectPos(w, new_pos);

	    /* if automaticselect is True, call XmNbrowseSelectionCallback */
	    if (event && List_AutoSelect(w))
	    {
		_XmListInvokeCallbacks(w, event, False);
	    }
	}
	break;

    case XmEXTENDED_SELECT:
	{
	    _XmListSetSelectRange(w, new_pos);
	    if (event && List_AutoSelect(w))
		_XmListInvokeCallbacks(w, event, False);
	}
	break;
    }
}

static void
ListDragTimeout(XtPointer closure,
		XtIntervalId *id)
{
    Widget w = (Widget)closure;
    int new_pos;
    Boolean redraw_all;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "ListDragTimeout() Dragging %s\n",
		      List_LeaveDir(w) == XmListDRAG_DOWN ? "down" : "up"));

    /* If we've dragged as far as we're gettin' */
    if ((List_LeaveDir(w) == XmListDRAG_DOWN &&
	 List_TopPosition(w) + List_VisibleItemCount(w) > List_ItemCount(w)) ||
	(List_LeaveDir(w) == XmListDRAG_UP && List_TopPosition(w) <= 1))
    {
	/* No more timeouts */
	List_DragID(w) = 0;
    }
    else
    {
	if (List_LeaveDir(w) == XmListDRAG_DOWN)
	{
	    new_pos = List_TopPosition(w) + List_VisibleItemCount(w);
	}
	else
	{
	    new_pos = List_TopPosition(w) - 1;
	}

	/* FIX ME - Where should we get the event causing the callback from? */
	ListDragToPos(w, NULL, new_pos, &redraw_all);
	_XmListSetTopPos(w, (List_TopPosition(w) +
			     (List_LeaveDir(w) == XmListDRAG_DOWN ? 1 : -1)),
			 &redraw_all);

	_XmListRedraw(w, redraw_all);
	List_DragID(w) = XtAppAddTimeOut(XtWidgetToApplicationContext(w),
					 XmListDRAG_TIMEOUT, ListDragTimeout,
					 (XtPointer)w);
    }
}

static void
ListButtonMotion(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    XButtonEvent *bevent = (XButtonEvent *)event;
    int new_pos;
    Boolean direction, redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListButtonMotion() action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT ||
	List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {

	int itemHeight = List_MaxItemHeight(w) +
	Prim_HighlightThickness(w) + 1 +
	List_ItemSpacing(w);

	/* If the pointer is below or above the list area */
	if ((direction = (int)event->xbutton.y >
	     (int)(Prim_ShadowThickness(w) + List_MarginHeight(w) +
		   itemHeight * List_VisibleItemCount(w))) ||
	    ((int)event->xbutton.y <
	     (int)(Prim_ShadowThickness(w) + List_MarginHeight(w))))
	{
	    /* Add timeout */
	    if (!List_DragID(w))
	    {
		List_LeaveDir(w) = direction ? XmListDRAG_DOWN : XmListDRAG_UP;
		List_DragID(w) =
		    XtAppAddTimeOut(XtWidgetToApplicationContext(w),
				    XmListDRAG_TIMEOUT, ListDragTimeout,
				    (XtPointer)w);
	    }
	}
	else
	{
	    if (List_DragID(w))
	    {
		/* Remove timeout */
		XtRemoveTimeOut(List_DragID(w));
		List_DragID(w) = 0;
	    }
	    new_pos = XmListYToPos(w, bevent->y + List_Vorigin(w));
	    if (List_LastItem(w) != new_pos)
		ListDragToPos(w, event, new_pos, &redraw_all);
	    _XmListRedraw(w, redraw_all);
	}
    }
}

static void
ListCopyToClipboard(Widget w, XEvent *event,
		    String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListCopyToClipboard()\n"));

    if (List_ItemCount(w) == 0 || List_SelectedItemCount(w) == 0)
    {
	return;
    }

    /* FIX ME */
}

static void
ListDefaultAction(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListDefaultAction()\n"));

    _XmListInvokeCallbacks(w, event, True);
    {
    XmParentProcessDataRec data;

	data.input_action.process_type = XmINPUT_ACTION;
	data.input_action.event = event;
	data.input_action.action = XmPARENT_ACTIVATE;
	data.input_action.params = params;
	data.input_action.num_params = num_params;

	if (XmIsManager(XtParent(w)) && 
	(((XmManagerWidgetClass)(XtClass(XtParent(w))))->manager_class.parent_process) != NULL)
	{
	    (((XmManagerWidgetClass)(XtClass(XtParent(w))))->manager_class.parent_process)(w, &data);
	}
    }
}

static void
ListEndData(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    int top_pos;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListEndData()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    top_pos = List_ItemCount(w) - List_VisibleItemCount(w) + 1;
    if (top_pos < 1)
    {
	top_pos = 1;
    }

    _XmListSetTopPos(w, top_pos, &redraw_all);
    _XmListSetCursorPos(w, List_ItemCount(w));

    if (!List_AddMode(w))
    {
	_XmListDeselectAll(w);
	_XmListSelectPos(w, List_ItemCount(w));
	_XmListInvokeCallbacks(w, event, False);
    }

    _XmListRedraw(w, redraw_all);
}


static void
ListEndDataExtend(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    int top_pos;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListEndDataExtend()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmMULTIPLE_SELECT ||
	List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	top_pos = List_ItemCount(w) - List_VisibleItemCount(w) + 1;
	if (top_pos < 1)
	    top_pos = 1;

	_XmListSetTopPos(w, top_pos, &redraw_all);
	_XmListSetCursorPos(w, List_ItemCount(w));

	if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
	{
	    _XmListSetSelectRange(w, List_ItemCount(w));

	    if (List_AutoSelect(w))
	    {
		_XmListInvokeCallbacks(w, event, False);
	    }
	}

	_XmListRedraw(w, redraw_all);
    }
}

static void
ListEndExtend(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    int new_top;
    Boolean redraw_all;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListEndExtend()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	new_top = List_LastItem(w) - List_VisibleItemCount(w) + 1;

	if (new_top < 1)
	{
	    new_top = 1;
	}

	_XmListSetTopPos(w, new_top, &redraw_all);
	_XmListSetCursorPos(w, List_LastItem(w));
	_XmListRedraw(w, redraw_all);
    }
}

static void
ListEndLine(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListEndLine()\n"));

    _XmListUpdateHorizScrollBar(w, List_Hmax(w), &redraw_all);

    if (redraw_all)
    {
	_XmListRedraw(w, True);
    }
}

/*
 * There must be a technical reason why (no time to dive into that), but
 * putting double-click in the translation table seems not to work. Too
 * complicated I guess.
 * Anyway, the consequence is we have to measure time to detect double-click
 * ourselves in here.
 * Motif has DownTime and DownCount fields in its structure so it must also be
 * doing this...
 */
static void
ListEndSelect(Widget w,
	      XEvent *event,
	      String *params,
	      Cardinal *num_params)
{
    XButtonEvent *bevent = (XButtonEvent *)event;
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListEndSelect() action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    /* Try to find double-click */
    if (List_DownCount(w) > 0 &&
	bevent->time < List_DownTime(w) + List_ClickInterval(w))
    {
	List_DownCount(w)++;

	ListDefaultAction(w, event, params, num_params);

	List_DownCount(w) = 0;

	return;			/* needed ? FIX ME */
    }
    else
    {
	List_DownTime(w) = bevent->time;
	List_DownCount(w) = 1;
    }

    if (Prim_Highlighted(w) && List_LastHLItem(w) != 0)
    {
	_XmListUnhighlight(w);
    }

    if (List_DragID(w))
    {
	XtRemoveTimeOut(List_DragID(w));
	List_DragID(w) = 0;
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT ||
	List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	List_LastHLItem(w) = XmListYToPos(w, bevent->y + List_Vorigin(w));
    }
    else
    {
	List_LastHLItem(w) = XmListYToPos(w, bevent->y + List_Vorigin(w));
    }

    if (List_LastItem(w))
    {
	_XmListSetCursorPos(w, List_LastItem(w));
    }

    _XmListRedraw(w, redraw_all);

    if ((List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	 List_SelectionPolicy(w) == XmMULTIPLE_SELECT) ||
	((List_SelectionPolicy(w) == XmBROWSE_SELECT ||
	  List_SelectionPolicy(w) == XmEXTENDED_SELECT) &&
	 List_AutoSelect(w) == False))
    {
	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListEndToggle(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    int new_top;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "ListEndToggle() last_item = %d\n", List_LastItem(w)));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	new_top = List_LastItem(w) - List_VisibleItemCount(w) + 1;

	if (new_top < 1)
	{
	    new_top = 1;
	}

	_XmListSetTopPos(w, new_top, &redraw_all);
	_XmListSetCursorPos(w, List_LastItem(w));

	if (!List_AutoSelect(w))
	{
	    _XmListInvokeCallbacks(w, event, False);
	}

	_XmListRedraw(w, redraw_all);
    }
}

static void
ListExtendNextItem(Widget w, XEvent *event,
		   String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListExtendNextItem()\n"));

    if (List_ItemCount(w) == 0 || List_LastHLItem(w) >= List_ItemCount(w))
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	if (List_StartItem(w) == 0)
	{
	    List_StartItem(w) = List_LastHLItem(w);
	}

	_XmListSetCursorPos(w, List_LastHLItem(w) + 1);

	if (List_LastHLItem(w) > (List_TopPosition(w) +
				  List_VisibleItemCount(w) - 1))
	{
	    _XmListSetTopPos(w, List_TopPosition(w) + 1, &redraw_all);
	}

	_XmListSetSelectRange(w, List_LastHLItem(w));
	_XmListRedraw(w, redraw_all);

	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListExtendPrevItem(Widget w, XEvent *event,
		   String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListExtendPrevItem()\n"));

    if (List_ItemCount(w) == 0 || List_LastHLItem(w) <= 1)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	if (List_StartItem(w) == 0)
	{
	    List_StartItem(w) = List_LastHLItem(w);
	}
	_XmListSetCursorPos(w, List_LastHLItem(w) - 1);

	if (List_LastHLItem(w) < List_TopPosition(w))
	{
	    _XmListSetTopPos(w, List_TopPosition(w) - 1, &redraw_all);
	}

	_XmListSetSelectRange(w, List_LastHLItem(w));
	_XmListRedraw(w, redraw_all);

	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListFocusIn(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListFocusIn() action\n"));

    XtCallActionProc(w, "PrimitiveFocusIn", event, params, *num_params);
}

static void
ListFocusOut(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListFocusOut() action\n"));

    XtCallActionProc(w, "PrimitiveFocusOut", event, params, *num_params);
}

static void
ListKbdActivate(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdActivate() action\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    _XmListInvokeCallbacks(w, event, True);
}

static void
ListKbdBeginExtend(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdBeginExtend()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    _XmListSetSelectRange(w, List_LastHLItem(w));
    _XmListRedraw(w, False);
}

static void
ListKbdBeginSelect(Widget w, XEvent *event,
		   String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdBeginSelect()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    switch (List_SelectionPolicy(w))
    {
    case XmSINGLE_SELECT:
	if (List_LastItem(w) != List_LastHLItem(w))
	{
	    if (List_LastItem(w))
	    {
		_XmListDeselectPos(w, List_LastItem(w));
	    }

	    _XmListSelectPos(w, List_LastHLItem(w));
	}
	break;

    case XmBROWSE_SELECT:
	if (List_LastItem(w))
	{
	    _XmListDeselectPos(w, List_LastItem(w));
	}

	_XmListSelectPos(w, List_LastHLItem(w));
	break;

    case XmMULTIPLE_SELECT:
	_XmListTogglePos(w, List_LastHLItem(w));
	break;

    case XmEXTENDED_SELECT:
	List_StartItem(w) = List_LastHLItem(w);
	if (List_AddMode(w))
	{
	    _XmListTogglePos(w, List_LastHLItem(w));
	}
	else
	{
	    _XmListDeselectAll(w);
	    _XmListSelectPos(w, List_LastHLItem(w));
	}

	if (List_AutoSelect(w))
	{
	    _XmListInvokeCallbacks(w, event, False);
	}

	break;
    }

    _XmListRedraw(w, False);
}

static void
ListKbdCancel(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdCancel()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	_XmListRestoreSelectRange(w);

	List_StartItem(w) = 0;

	_XmListRedraw(w, False);
    }
}

static void
ListKbdDeSelectAll(Widget w, XEvent *event,
		   String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdDeSelectAll()\n"));

    if (List_ItemCount(w) == 0 || List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	List_SelectionPolicy(w) == XmMULTIPLE_SELECT ||
	(List_SelectionPolicy(w) == XmEXTENDED_SELECT &&
	 List_AddMode(w)))
    {
	_XmListDeselectAll(w);
    }
    else if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	/* XXX - we are meant to leave the item at the cursor position alone
	 * here if the shell's XmNkeyboardFocusPolicy is XmEXPLICIT */
	_XmListDeselectAll(w);
    }

    _XmListInvokeCallbacks(w, event, False);
    _XmListRedraw(w, False);
}

static void
ListKbdEndExtend(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdEndExtend()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT && !List_AutoSelect(w))
    {
	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListKbdEndSelect(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdEndSelect()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    if (List_SelectionPolicy(w) == XmSINGLE_SELECT ||
	List_SelectionPolicy(w) == XmMULTIPLE_SELECT ||
	!List_AutoSelect(w))
    {
	_XmListInvokeCallbacks(w, event, False);
    }
}

static void
ListKbdSelectAll(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListKbdSelectAll()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    switch (List_SelectionPolicy(w))
    {
    case XmSINGLE_SELECT:
    case XmBROWSE_SELECT:
	if (List_LastItem(w) != List_LastHLItem(w))
	{
	    if (List_LastItem(w))
	    {
		XmListDeselectPos(w, List_LastItem(w));
	    }

	    _XmListSelectPos(w, List_LastHLItem(w));
	}
	break;

    case XmMULTIPLE_SELECT:
    case XmEXTENDED_SELECT:
	_XmListSelectAll(w);
	break;
    }

    _XmListRedraw(w, False);
    _XmListInvokeCallbacks(w, event, False);
}

static void
ListLeftChar(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListLeftChar()\n"));

    _XmListUpdateHorizScrollBar(w, List_Horigin(w) - List_CharWidth(w),
				&redraw_all);
    if (redraw_all)
    {
	_XmListRedraw(w, True);
    }
}

static void
ListLeftPage(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListLeftPage()\n"));

/**starving**/
}

static void
ListNextItem(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListNextItem()\n"));

    if (List_ItemCount(w) == 0 || List_LastHLItem(w) == List_ItemCount(w))
    {
	return;
    }

    assert(List_LastHLItem(w) > 0 && List_LastHLItem(w) <= List_ItemCount(w));

    _XmListSetCursorPos(w, List_LastHLItem(w) + 1);

    if (List_LastHLItem(w) > (List_TopPosition(w) +
			      List_VisibleItemCount(w) - 1))
    {
	_XmListSetTopPos(w, List_TopPosition(w) + 1, &redraw_all);
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	_XmListDeselectPos(w, List_LastHLItem(w) - 1);
	_XmListSelectPos(w, List_LastHLItem(w));
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT && !List_AddMode(w))
    {
	_XmListDeselectAll(w);
	List_StartItem(w) = List_LastHLItem(w);
	_XmListSelectPos(w, List_LastHLItem(w));
    }

    _XmListRedraw(w, redraw_all);
}

static void
ListNextPage(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    int position, new_top;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListNextPage()\n"));

    if (List_ItemCount(w) == 0)
    {
	return;
    }

    /* Move down a page - 1 item.  Move the top of the list the same amount,
     * so the cursor stays at the same point on the screen */
    position = List_LastHLItem(w) + List_VisibleItemCount(w) - 1;
    if (position > List_ItemCount(w))
    {
	position = List_ItemCount(w);
    }

    new_top = List_TopPosition(w) + List_VisibleItemCount(w) - 1;

    if (List_VisibleItemCount(w) == 1)
    {
	position++;
	new_top++;
    }

    if (new_top > List_ItemCount(w) - List_VisibleItemCount(w) + 1)
    {
	new_top = List_ItemCount(w) - List_VisibleItemCount(w) + 1;
	if (new_top < 1)
	{
	    new_top = 1;
	}
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	_XmListDeselectPos(w, List_LastHLItem(w));
	_XmListSelectPos(w, position);
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT && !List_AddMode(w))
    {
	_XmListDeselectAll(w);
	List_StartItem(w) = position;
	_XmListSelectPos(w, position);
    }

    _XmListSetTopPos(w, new_top, &redraw_all);
    _XmListSetCursorPos(w, position);
    _XmListRedraw(w, redraw_all);
}

static void
ListPrevItem(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListPrevItem()\n"));

    if (List_ItemCount(w) == 0 || List_LastHLItem(w) == 1)
    {
	return;
    }

    assert(List_LastHLItem(w) > 0 && List_LastHLItem(w) <= List_ItemCount(w));

    _XmListSetCursorPos(w, List_LastHLItem(w) - 1);
    if (List_LastHLItem(w) < List_TopPosition(w))
    {
	_XmListSetTopPos(w, List_LastHLItem(w), &redraw_all);
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	_XmListDeselectPos(w, List_LastHLItem(w) + 1);
	_XmListSelectPos(w, List_LastHLItem(w));
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT && !List_AddMode(w))
    {
	_XmListDeselectAll(w);
	List_StartItem(w) = List_LastHLItem(w);
	_XmListSelectPos(w, List_LastHLItem(w));
    }

    _XmListRedraw(w, redraw_all);
}

static void
ListPrevPage(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    int position, new_top;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListPrevPage()\n"));

    if (List_ItemCount(w) == 0 || List_LastHLItem(w) == 1)
    {
	return;
    }

    position = List_LastHLItem(w) - List_VisibleItemCount(w) + 1;
    if (List_VisibleItemCount(w) == 1)
    {
	position--;
    }
    if (position < 1)
    {
	position = 1;
    }

    new_top = List_TopPosition(w) - List_VisibleItemCount(w) + 1;
    if (List_VisibleItemCount(w) == 1)
    {
	new_top--;
    }
    if (new_top < 1)
    {
	new_top = 1;
    }

    if (List_SelectionPolicy(w) == XmBROWSE_SELECT)
    {
	_XmListDeselectPos(w, List_LastHLItem(w));

	_XmListSelectPos(w, position);
    }

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT && !List_AddMode(w))
    {
	_XmListDeselectAll(w);

	List_StartItem(w) = position;

	_XmListSelectPos(w, position);
    }

    _XmListSetCursorPos(w, position);
    _XmListSetTopPos(w, new_top, &redraw_all);

    _XmListRedraw(w, redraw_all);
}

static void
ListProcessDrag(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    /* CHECK TO SEE IF THE EXPORT TARGET IS REALLY COMPOUND_TEXT -- FIX ME ! */
    int position;
    Atom export_target;
    Arg args[10];
    int n = 0;
    Widget dc;

    DEBUGOUT(XdbDebug(__FILE__, w, "ListProcessDrag()\n"));

    /* If the list is empty, they couldn't really have dragged from it,
     * now could they? */
    if (List_ItemCount(w) == 0)
    {
	return;
    }

    /* set up some stuff */
    export_target = XmInternAtom(XtDisplay(w),
				 _XA_COMPOUND_TEXT,
				 False);

    XtSetArg(args[n], XmNexportTargets, &export_target); n++;
    XtSetArg(args[n], XmNnumExportTargets, 1); n++;
    XtSetArg(args[n], XmNdragOperations, XmDROP_COPY); n++;
    XtSetArg(args[n], XmNclientData, w); n++;

    /* determine the item that they dragged from */
    position = XmListYToPos(w, event->xbutton.y + List_Vorigin(w));

    if (position > List_ItemCount(w))
    {
	position = List_ItemCount(w);
    }

    /* now decide whether the item was selected or not.  If it was, we want
       to transfer all the selected items.  If not, we only want to transfer
       the item they dragged from.

       position is +1 since XmListYToPos can return 0 */

    if (XmListPosSelected(w, position /* + 1 */ ))
    {
	/* the position was selected.  drag all the selected positions */
	XtSetArg(args[n], XmNconvertProc, drag_selected_proc); n++;
    }
    else
    {
	/* the position wasn't selected.  drag only the one item */
	XtSetArg(args[n], XmNconvertProc, drag_unselected_proc); n++;
    }
    dc = XmDragStart(w, event, args, n);

    XtAddCallback(dc, XmNdragDropFinishCallback, drag_drop_finish, NULL);
}

static void
ListRightChar(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "ListRightChar()\n"));

    _XmListUpdateHorizScrollBar(w, List_Horigin(w) + List_CharWidth(w),
				&redraw_all);
    if (redraw_all)
    {
	_XmListRedraw(w, True);
    }
}

static void
ListRightPage(Widget w, XEvent *event, String *params, Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "ListRightPage()\n"));

    /**starving**/
}


Widget
XmCreateList(Widget parent, char *name, Arg *arglist, Cardinal argCount)
{
    return XtCreateWidget(name, xmListWidgetClass, parent, arglist, argCount);
}

Widget
XmCreateScrolledList(Widget parent, char *name, Arg *arglist, Cardinal argCount)
{
    Widget sw;
    char *sname;
    int i;
    Arg *al;

    sname = XtMalloc(strlen(name) + 3);
    strcpy(sname, name);
    strcat(sname, "SW");

    al = (Arg *)XtCalloc(argCount + 4, sizeof(Arg));
    for (i = 0; i < argCount; i++)
    {
	al[i].name = arglist[i].name;
	al[i].value = arglist[i].value;
    }

    XtSetArg(al[i], XmNscrollingPolicy, XmAPPLICATION_DEFINED); i++;
    XtSetArg(al[i], XmNvisualPolicy, XmVARIABLE); i++;
    XtSetArg(al[i], XmNscrollBarDisplayPolicy, XmSTATIC); i++;
    XtSetArg(al[i], XmNshadowThickness, 0); i++;

    sw = XtCreateManagedWidget(sname, xmScrolledWindowWidgetClass, parent,
			       al, i);
    XtFree((XtPointer)al);
    XtFree((XtPointer)sname);

    return XtCreateWidget(name, xmListWidgetClass, sw, arglist, argCount);
}

void
XmListAddItem(Widget w,
	      XmString item,
	      int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListAddItem()\n"));

    if (position < 0)
    {
	/* do some warning type stuff here... */
	position = 0;
    }
    if (position > (List_ItemCount(w) + 1))
    {
	/* do some warning type stuff here... */
	position = 0;
    }

    _XmListAddItemUnselected(w, item, position);
    _XmListSelectPosIfMatch(w, position);
    _XmListRedraw(w, True);
}

void
XmListAddItems(Widget w,
	       XmString *items,
	       int item_count,
	       int position)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListAddItems\n"));

    if (position <= 0 || (position > List_ItemCount(w) + 1))
    {
	position = List_ItemCount(w);
    }

    _XmListAddItemsUnselected(w, items, item_count, position);

    for (i = 0; i < item_count; ++i)
    {
	_XmListSelectPosIfMatch(w, position + i);
    }

    _XmListRedraw(w, True);
}

void
XmListAddItemUnselected(Widget w, XmString item, int position)
{
    /*DEBUGOUT(XdbDebug(__FILE__, w,
     *                        "XmListAddItemUnselected(%s, %d)\n",
     *                  XdbXmString2String(item), position)); */

    _XmListAddItemUnselected(w, item, position);

    _XmListSetGeometry(w);

    _XmListRedraw(w, True);
}

void
XmListAddItemsUnselected(Widget w, XmString *items, int item_count,
			 int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		      "XmListAddItemsUnselected(_, count %d, pos %d)\n",
		      item_count, position));

    _XmListAddItemsUnselected(w, items, item_count, position);
    _XmListSetGeometry(w);

    _XmListRedraw(w, True);
}

void
XmListDeleteAllItems(Widget w)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeleteAllItems()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	XmStringFree(List_Items(w)[i]);
    }

    List_ItemCount(w) = List_SelectedItemCount(w) = List_LastItem(w) = 0;

    _XmListSetGeometry(w);

    _XmListRedraw(w, True);
}

void
XmListDeleteItem(Widget w, XmString item)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeleteItem()\n"));

    if (_XmListDeleteItem(w, item))
    {
	_XmListSetGeometry(w);

	_XmListRedraw(w, True);
    }
    else
    {
	XtWarning("XmListDeleteItem: item not found in list.\n");
    }
}

void
XmListDeleteItems(Widget w, XmString *items, int item_count)
{
    Boolean need_refresh = False;
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeleteItems()\n"));

    for (i = 0; i < item_count; ++i)
    {
	need_refresh |= _XmListDeleteItem(w, items[i]);
    }

    if (need_refresh)
    {
	_XmListSetGeometry(w);

	_XmListRedraw(w, True);
    }
}

void
XmListDeleteItemsPos(Widget w, int item_count, int position)
{
    int i = 0;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeleteItemsPos()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	XtWarning("XmDeleteItemsPos: position not in list bounds.\n");
	return;
    }

    if (position)
    {
	while (i++ < item_count && position <= List_ItemCount(w))
	    _XmListDeletePos(w, position);
    }
    else
    {
	_XmListDeletePos(w, List_ItemCount(w));
    }

    _XmListSetGeometry(w);

    _XmListRedraw(w, True);
}

void
XmListDeletePos(Widget w, int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeletePos()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	XtWarning("XmDeletePos: position is not within list bounds.\n");
	return;
    }

    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    _XmListDeletePos(w, position);
    _XmListSetGeometry(w);

    _XmListRedraw(w, True);
}

void
XmListDeletePositions(Widget w, int *position_list, int position_count)
{
    int i, j;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeletePositions()\n"));

    for (i = 0; i < position_count; ++i)
    {
	position_list[i] = (position_list[i] ? position_list[i] :
			    List_ItemCount(w));
    }

    for (i = List_ItemCount(w); i > 0; --i)
    {
	for (j = 0; j < position_count; ++j)
	{
	    if (position_list[j] == i)
	    {
		_XmListDeletePos(w, i);
		break;
	    }
	}
    }

    _XmListSetGeometry(w);
    _XmListRedraw(w, True);
}

void
XmListDeselectAllItems(Widget w)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeselectAllItems()\n"));

    _XmListDeselectAll(w);
    _XmListRedraw(w, False);
}

void
XmListDeselectItem(Widget w, XmString item)
{
    int i;
    _XmString str;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeselectItem()\n"));

    str = _XmStringCreate(item);

    for (i = 0; i < List_ItemCount(w); i++)
    {
	if (_XmStringByteCompare(str, List_InternalList(w)[i]->name))
	{
	    XmListDeselectPos(w, i + 1);
	}
    }

    _XmStringFree(str);
}

void
XmListDeselectPos(Widget w, int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListDeselectPos()\n"));

    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    if (position < 0)
    {
	position = List_ItemCount(w) - 1;	/* Not in the specs */
    }

    if (_XmListDeselectPos(w, position))
    {
	_XmListRedraw(w, False);
    }
    else
    {
	_XmWarning(w,
		   "XmListDeselectPos(%d) : item not found in selectedItems.\n",
		   position);
    }
}

int
XmListGetKbdItemPos(Widget w)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListGetKbdItemPos()\n"));

    return List_LastHLItem(w);
}


Boolean
XmListGetMatchPos(Widget w, XmString item,
		  int **position_list, int *position_count)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListGetMatchPos()\n"));

    *position_count = 0;
    position_list = NULL;

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    *position_list = (int *)XtRealloc((XtPointer)*position_list,
					      *position_count * sizeof(int));

	    (*position_list)[(*position_count)++] = i + 1;
	}
    }

    return *position_count ? True : False;
}

Boolean
XmListGetSelectedPos(Widget w, int **position_list, int *position_count)
{
    int i, j;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListGetSelectPos()\n"));

    *position_count = List_SelectedItemCount(w);

    if (*position_count == 0)
	return False;

    *position_list = (int *)XtMalloc(*position_count * sizeof(int));

    j = 0;
    i = 0;
    while (i < List_ItemCount(w))
    {
	if (List_InternalList(w)[i]->selected)
	{
	    (*position_list)[j++] = i + 1;
	}

	if (j > *position_count)
	{
	    _XmWarning(w,
	       "XmGetSelectedPos: Found more selected items than expected.\n");
	    break;
	}

	i++;
    }

    return True;
}

Boolean
XmListItemExists(Widget w, XmString item)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListItemExists()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    return True;
	}
    }

    return False;
}

int
XmListItemPos(Widget w, XmString item)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListItemPos()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    return i + 1;
	}
    }

    return 0;
}

Boolean
XmListPosSelected(Widget w, int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListPosSelected()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	return False;
    }

    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    return List_InternalList(w)[position - 1]->selected;
}

Boolean
XmListPosToBounds(Widget w,
		  int position,
		  Position *x,
		  Position *y,
		  Dimension *width,
		  Dimension *height)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListPosToBounds()\n"));

    if (!position)
    {
	position = List_ItemCount(w);
    }

    if (position < List_TopPosition(w) ||
	position >= List_TopPosition(w) + List_VisibleItemCount(w))
    {
	return False;
    }

    if (x)
    {
	*x = (List_MarginWidth(w)
	      + Prim_ShadowThickness(w)
	      + Prim_HighlightThickness(w));
    }

    if (width)
    {
	*width = List_InternalList(w)[position - 1]->width;
    }

    if (height)
    {
	*height = List_InternalList(w)[position - 1]->height;
    }

    if (y)
    {
	*y = ((Prim_ShadowThickness(w)
	       + List_MarginHeight(w)
	       + Prim_HighlightThickness(w))
#ifdef USE_CUM_HEIGHT
	      + (List_InternalList(w)[position - 1]->CumHeight
		 - List_InternalList(w)[position - 1]->height
#else
	      + (List_MaxItemHeight(w) * (position - 1)
#endif
		 - List_Vorigin(w)));
    }

    return True;
}

void
_XmListReplaceItemPos(Widget w, int _pos, XmString new_item)
{
    Dimension height, width;

    /* deallocate the item */
    XmStringFree(List_Items(w)[_pos]);
    _XmStringFree(List_InternalList(w)[_pos]->name);

    /* replace with new_item */
    List_Items(w)[_pos] = XmStringCopy(new_item);
    List_InternalList(w)[_pos]->name = _XmStringCreate(new_item);

    XmStringExtent(List_Font(w), new_item, &width, &height);
    List_InternalList(w)[_pos]->width = width;
    List_InternalList(w)[_pos]->height = height;
    List_InternalList(w)[_pos]->length = XmStringLength(new_item);

}


void
XmListReplaceItems(Widget w, XmString *old_items, int item_count,
		   XmString *new_items)
{
    int i, j;
    Boolean need_refresh = False;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListReplaceItems()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {

	for (j = 0; j < List_ItemCount(w); ++j)
	{

	    /* see if item in old_items[] matches item in list */
	    if (XmStringCompare(old_items[i], List_Items(w)[j]))
	    {

		/* we have a match */
		need_refresh = True;

		/* deselect the item */
		(void)_XmListDeselectPos(w, j);

#ifdef OLD_31_OCT
		/* deallocate the item */
		XmStringFree(List_Items(w)[j]);

		/* replace with corresponding item from new_items[] */
		List_Items(w)[j] = XmStringCopy(new_items[i]);

#else
		_XmListReplaceItemPos(w, j, new_items[i]);
#endif

		/* set selected if match item in selected items list */
		_XmListSelectPosIfMatch(w, j);
	    }
	}
    }

    if (need_refresh)
    {
	_XmListRedraw(w, True);
    }
}

void
XmListReplaceItemsPos(Widget w, XmString *new_items, int item_count, int position)
{
    int i, j = (position ? position : List_ItemCount(w)) - 1;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListReplaceItemsPos(%d)\n", j));

    for (i = 0; i < item_count && j < List_ItemCount(w); ++i)
    {
	(void)_XmListDeselectPos(w, j);

#ifdef OLD_31_OCT
	XmStringFree(List_Items(w)[j]);
	List_Items(w)[j] = XmStringCopy(new_items[i]);
#else
	_XmListReplaceItemPos(w, j, new_items[i]);
#endif

	/* FIX ME : The two statements below can be combined to be more
	 * efficient, if the semantics of _XmListSelectPosIfMatch can be
	 * changed so it'll deselect stuff as well.
	 * There's a good chance that this can be done */

	(void)_XmListDeselectPos(w, j);		/* Danny 23/7/97 */

	_XmListSelectPosIfMatch(w, j);

	j++;
    }

    _XmListRedraw(w, True);
}

void
XmListReplaceItemsPosUnselected(Widget w, XmString *new_items, int item_count,
				int position)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListReplaceItemsPosUnselected()\n"));

    if (!position)
    {
	position = List_ItemCount(w);
    }

    for (i = 0; i < item_count && position < List_ItemCount(w); i++, position++)
    {
	(void)_XmListDeselectPos(w, position);

#ifdef OLD_31_OCT
	XmStringFree(List_Items(w)[position - 1]);
	List_Items(w)[position - 1] = XmStringCopy(new_items[i]);
#else
	_XmListReplaceItemPos(w, position - 1, new_items[i]);
#endif
    }

    _XmListRedraw(w, True);
}

void
XmListReplaceItemsUnselected(Widget w, XmString *old_items, int item_count, XmString *new_items)
{
    Boolean need_refresh = False;
    int i, j;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListReplaceItemsUnselected()\n"));

    for (i = 0; i < item_count; ++i)
    {
	for (j = 0; j < List_ItemCount(w); ++j)
	{
	    if (XmStringCompare(old_items[i], List_Items(w)[j]))
	    {
		need_refresh = True;
		(void)_XmListDeselectPos(w, j);
#ifdef OLD_31_OCT
		XmStringFree(List_Items(w)[j]);
		List_Items(w)[j] = XmStringCopy(new_items[i]);
#else
		_XmListReplaceItemPos(w, j, new_items[i]);
#endif
	    }
	}
    }

    if (need_refresh)
    {
	_XmListRedraw(w, True);
    }
}

void
XmListReplacePositions(Widget w, int *position_list, XmString *item_list, int item_count)
{
    int i, j;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListReplacePosition()\n"));

    for (i = 0; i < item_count; ++i)
    {
	j = (position_list[i] ? position_list[i] : List_ItemCount(w)) - 1;

	(void)_XmListDeselectPos(w, j);

	if (position_list[i] > List_ItemCount(w))
	{
	    /* print a warning */
#ifdef OLD_31_OCT
	    List_Items(w)[j] = XmStringCopy(item_list[i]);
#else
	    _XmListReplaceItemPos(w, j, item_list[i]);
#endif
	    (void)_XmListDeselectPos(w, j);	/* Danny 23/7/97 */

	    _XmListSelectPosIfMatch(w, j);
	}
    }

    _XmListRedraw(w, True);
}

void
XmListSelectItem(Widget w, XmString item, Boolean notify)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSelectItem()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    XmListSelectPos(w, i + 1, notify);

	    return;
	}
    }
}

void
XmListSelectPos(Widget w, int position, Boolean notify)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSelectPos()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	return;
    }

    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    /* XmEXTENDED_SELECT : clear current selection first */
    /* See ddd-2.1 bug #12 */
    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	_XmListDeselectAll(w);
    }

    _XmListSelectPos(w, position);
    _XmListRedraw(w, False);

    if (notify)
    {
	XAnyEvent *event = (XAnyEvent *)XtMalloc(sizeof(XAnyEvent));
	event->type = 0;
	event->serial = 0;
	event->send_event = False;
	event->display = XtDisplay(w);
	event->window = XtWindow(w);

	_XmListInvokeCallbacks(w, (XEvent *)event, False);

	XtFree((XtPointer)event);
    }
}

void
XmListSetAddMode(Widget w, Boolean mode)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetAddMode()\n"));

    if (List_SelectionPolicy(w) == XmEXTENDED_SELECT)
    {
	List_AddMode(w) = mode;
    }
}

void
XmListSetBottomItem(Widget w, XmString item)
{
    Boolean redraw_all = False;
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetBottomItem()\n"));

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    _XmListSetTopPos(w, i - List_VisibleItemCount(w) + 2,
			     &redraw_all);
	    _XmListRedraw(w, redraw_all);
	    break;
	}
    }
}

void
XmListSetBottomPos(Widget w, int position)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetBottomPos()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	return;
    }

    if (position == 0)
    {
	position = List_ItemCount(w);
    }

    /* Ensure that position - List_VisibleItemCount(w) + 1 >= 1 */
    if (position < List_VisibleItemCount(w))
    {
	_XmListSetTopPos(w, 1, &redraw_all);
    }
    else
    {
	_XmListSetTopPos(w, position - List_VisibleItemCount(w) + 1,
			 &redraw_all);
    }

    _XmListRedraw(w, redraw_all);
}

void
XmListSetHorizPos(Widget w, int position)
{
    Boolean redraw_all = False;

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "XmListSetHorizPos()      List_MaxWidth() = %d\n",
		      List_MaxWidth(w)));

    if (!List_IsScrolledList(w) || !XtIsManaged(List_HSB(w)))
    {
	return;
    }

    if (position < List_Hmin(w))
    {
	position = List_Hmin(w);
    }
    else if (position > List_Hmax(w))
    {
	position = List_Hmax(w);
    }

    _XmListUpdateHorizScrollBar(w, position, &redraw_all);

    if (redraw_all)
    {
	_XmListRedraw(w, True);
    }
}

void
XmListSetItem(Widget w, XmString item)
{
    Boolean redraw_all = False;
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetItem()\n"));

    for (i = 0; i < List_SelectedItemCount(w); ++i)
    {
	if (XmStringCompare(item, List_Items(w)[i]))
	{
	    _XmListSetTopPos(w, i + 1, &redraw_all);
	    _XmListRedraw(w, redraw_all);
	    break;
	}
    }
}

Boolean
XmListSetKbdItemPos(Widget w, int position)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetKbdItemPos()\n"));

    if (position < 0 || position > List_ItemCount(w) || !List_ItemCount(w))
    {
	return False;
    }

    if (!position)
    {
	position = List_ItemCount(w);
    }

    _XmListSetCursorPos(w, position);
    _XmListRedraw(w, False);

    return True;
}

void
XmListSetPos(Widget w, int position)
{
    Boolean redraw_all = False;
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListSetPos()\n"));

    if (position < 0 || position > List_ItemCount(w))
    {
	return;
    }

    if (!position)
    {
	position = List_ItemCount(w);
    }

    _XmListSetTopPos(w, position, &redraw_all);
    _XmListRedraw(w, redraw_all);
}

/* 
 * This function frees the existing XmNselectedItems list, then
 * recreates it.  It is used to resynch the XmNselectedItems
 * if you have messed with some internal XmList structures and
 * possibly screwed things up.  This function is clearly a 
 * kluge.
 */
void
XmListUpdateSelectedList(Widget w)
{
    int i;

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListUpdateSelectedList()\n"));

    /* reallocate the XmNselectedItems */
    List_SelectedItems(w) =
	(XmStringTable)XtRealloc((XtPointer)List_SelectedItems(w),
				 List_ItemCount(w) *
				 sizeof(XmString));

    /* reset the selected count to zero */
    List_SelectedItemCount(w) = 0;

    for (i = 0; i < List_ItemCount(w); ++i)
    {
	if (List_InternalList(w)[i]->selected)
	{
	    List_SelectedItems(w)[List_SelectedItemCount(w)++] =
		XmStringCopy(List_Items(w)[i]);
	}
    }

    _XmListRedraw(w, True);
}

int
XmListYToPos(Widget w, Position y)
{
    int calculated_pos;
    int item_height;
    int margin = List_MarginHeight(w) + Prim_ShadowThickness(w);

    DEBUGOUT(XdbDebug(__FILE__, w, "XmListYToPos()\n"));

    y -= List_Vorigin(w) + margin + Prim_HighlightThickness(w) +
	List_ItemSpacing(w);

    if (List_ItemCount(w) == 0)
    {
	return 0;
    }

    item_height = List_MaxItemHeight(w) + Prim_HighlightThickness(w) + 1 +
	List_ItemSpacing(w);

    calculated_pos = (y - margin) / item_height + List_TopPosition(w);

    if (calculated_pos > List_ItemCount(w))
    {
	calculated_pos = List_ItemCount(w);
    }
    if (calculated_pos < List_TopPosition(w))
    {
	calculated_pos = List_TopPosition(w);
    }
    if (calculated_pos > List_TopPosition(w) + List_VisibleItemCount(w) - 1)
    {
	calculated_pos = List_TopPosition(w) + List_VisibleItemCount(w) - 1;
    }

#ifdef DO_SANITY
    if (calculated_pos < 1)
    {
	_XmWarning(w, "XmListYToPos: impossible position %d in %s %d\n",
		   calculated_pos, __FILE__, __LINE__);
	calculated_pos = 0;
    }
#endif

    return calculated_pos;
}

/* 
 * This routine determines the preferred size of List.
 */
static XtGeometryResult
query_geometry(Widget w, XtWidgetGeometry *proposed, XtWidgetGeometry *answer)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "query_geometry\n"));

    answer->request_mode = CWWidth | CWHeight;
    answer->width = _XmListBestWidth(w);
    answer->height = _XmListBestHeight(w);

    DEBUGOUT(XdbDebug(__FILE__, w,
		      "query_geometry  => W %d H %d (items %d visible %d)\n",
		      answer->width, answer->height,
		      List_ItemCount(w), List_VisibleItemCount(w)));

    if (((proposed->request_mode & CWWidth) &&
	 proposed->width >= answer->width) &&
	((proposed->request_mode & CWHeight) &&
	 proposed->height >= answer->height))
    {
	return XtGeometryYes;
    }

    if (proposed->width == XtWidth(w) && proposed->height == XtHeight(w))
    {
	if (answer)
	{
	    answer->request_mode = 0;
	}
	return XtGeometryNo;
    }
    else
    {
	return XtGeometryAlmost;
    }
}

static void
list_border_highlight(Widget w)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		      "list_border_highlight() LastHLItem: %d Top: %d\n",
		      List_LastHLItem(w), List_TopPosition(w)));

    Prim_Highlighted(w) = True;
    Prim_HighlightDrawn(w) = True;

    _XmListHighlight(w);
}


static void
list_border_unhighlight(Widget w)
{
    DEBUGOUT(XdbDebug(__FILE__, w,
		      "list_border_unhighlight() LastHLItem: %d\n",
		      List_LastHLItem(w)));

    if (!XtIsManaged(w))
    {
	return;
    }

    Prim_Highlighted(w) = False;
    Prim_HighlightDrawn(w) = False;

    _XmListUnhighlight(w);
}

static void
ListLeave(Widget w,
	  XEvent *event,
	  String *params,
	  Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListLeave()\n"));

    XtCallActionProc(w, "PrimitiveLeave", event, params, *num_params);
}

static void
ListEnter(Widget w,
	  XEvent *event,
	  String *params,
	  Cardinal *num_params)
{
    DEBUGOUT(XdbDebug(__FILE__, w, "XmListEnter()\n"));

    XtCallActionProc(w, "PrimitiveEnter", event, params, *num_params);
}

static Boolean
drag_selected_proc(Widget w,
		   Atom *selection,
		   Atom *target,
		   Atom *type_return,
		   XtPointer *value_return,
		   unsigned long *length_return,
		   int *format_return)
{
    Atom COMPOUND_TEXT;
    Atom MOTIF_DROP;

    COMPOUND_TEXT = XmInternAtom(XtDisplay(w), _XA_COMPOUND_TEXT, False);
    MOTIF_DROP = XmInternAtom(XtDisplay(w), _XA_MOTIF_DROP, False);

    if (*selection != MOTIF_DROP)
    {
	return False;
    }

    DEBUGOUT(XdbDebug(__FILE__, w, "We're dealing with a motif drop\n"));

    return False;
}

static Boolean
drag_unselected_proc(Widget w,
		     Atom *selection,
		     Atom *target,
		     Atom *type_return,
		     XtPointer *value_return,
		     unsigned long *length_return,
		     int *format_return)
{
    Atom COMPOUND_TEXT;
    Atom MOTIF_DROP;

    COMPOUND_TEXT = XmInternAtom(XtDisplay(w), _XA_COMPOUND_TEXT, False);
    MOTIF_DROP = XmInternAtom(XtDisplay(w), _XA_MOTIF_DROP, False);

    if (*selection != MOTIF_DROP)
    {
	return False;
    }

    DEBUGOUT(XdbDebug(__FILE__, w, "We're dealing with a motif drop\n"));

    return False;
}

static void
drag_drop_finish(Widget w,
		 XtPointer client_data,
		 XtPointer call_data)
{
}
