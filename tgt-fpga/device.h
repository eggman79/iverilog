#ifndef __device_H
#define __device_H
/*
 * Copyright (c) 2001 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#if !defined(WINNT) && !defined(macintosh)
#ident "$Id: device.h,v 1.8 2002/08/11 23:47:04 steve Exp $"
#endif

# include  <ivl_target.h>

/*
 * This code generator supports a variety of device types. It does
 * this by keeping a device "driver" structure for each device
 * type. The device structure contains pointers to functions that emit
 * the proper XNF for a given type of device.
 *
 * If a device supports a method, the function pointer is filled in
 * with a pointer to the proper function.
 *
 * If a device does not support the method, then the pointer is null.
 */
typedef const struct device_s* device_t;

struct device_s {
	/* These methods draw leading and trailing format text. */
      void (*show_header)(ivl_design_t des);
      void (*show_footer)(ivl_design_t des);
	/* Draw pads connected to the specified signal. */
      void (*show_pad)(ivl_signal_t sig, const char*str);
	/* Draw basic logic devices. */
      void (*show_logic)(ivl_net_logic_t net);
	/* This method emits a D type Flip-Flop */
      void (*show_dff)(ivl_lpm_t net);
	/* These methods show various comparators */
      void (*show_cmp_eq)(ivl_lpm_t net);
      void (*show_cmp_ne)(ivl_lpm_t net);
	/* This method draws MUX devices */
      void (*show_mux)(ivl_lpm_t net);
	/* This method draws ADD devices */
      void (*show_add)(ivl_lpm_t net);
};

/*
 * Return the device_t cookie given the name of the architecture. If
 * the device is not found, return 0.
 *
 * This function is used if the user specifies the archetecture
 * explicitly, with the -parch=name flag.
 */
extern device_t device_from_arch(const char*arch);


/*
 * $Log: device.h,v $
 * Revision 1.8  2002/08/11 23:47:04  steve
 *  Add missing Log and Ident strings.
 *
 * Revision 1.7  2001/09/16 01:48:16  steve
 *  Suppor the PAD attribute on signals.
 *
 * Revision 1.6  2001/09/02 21:33:07  steve
 *  Rearrange the XNF code generator to be generic-xnf
 *  so that non-XNF code generation is also possible.
 *
 *  Start into the virtex EDIF output driver.
 *
 * Revision 1.5  2001/09/01 04:30:44  steve
 *  Generic ADD code.
 *
 * Revision 1.4  2001/09/01 02:28:42  steve
 *  Generate code for MUX devices.
 *
 * Revision 1.3  2001/09/01 02:01:30  steve
 *  identity compare, and PWR records for constants.
 *
 * Revision 1.2  2001/08/31 02:59:06  steve
 *  Add root port SIG records.
 *
 * Revision 1.1  2001/08/28 04:14:20  steve
 *  Add the fpga target.
 *
 */
#endif
