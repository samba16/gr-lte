/* -*- c++ -*- */
/* 
 * Copyright 2012 Communications Engineering Lab (CEL) / Karlsruhe Institute of Technology (KIT)
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_LTE_TAG_SYMBOL_CC_H
#define INCLUDED_LTE_TAG_SYMBOL_CC_H

#include <lte_api.h>
#include <gr_sync_block.h>

class lte_tag_symbol_cc;
typedef boost::shared_ptr<lte_tag_symbol_cc> lte_tag_symbol_cc_sptr;

LTE_API lte_tag_symbol_cc_sptr lte_make_tag_symbol_cc (int offset, int fftl);

/*!
 * \brief <+description+>
 *
 */
class LTE_API lte_tag_symbol_cc : public gr_sync_block
{
	friend LTE_API lte_tag_symbol_cc_sptr lte_make_tag_symbol_cc (int offset, int fftl);

	lte_tag_symbol_cc (int offset, int fftl);

 public:
	~lte_tag_symbol_cc ();


	int work (int noutput_items,
		gr_vector_const_void_star &input_items,
		gr_vector_void_star &output_items);

 private:
    int d_offset;
    int d_fftl;
    pmt::pmt_t d_key;
    pmt::pmt_t d_id_key;
	pmt::pmt_t d_tag_id;
	int d_slot_num;
};

#endif /* INCLUDED_LTE_TAG_SYMBOL_CC_H */

