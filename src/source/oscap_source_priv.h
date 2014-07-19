/*
 * Copyright 2014 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author:
 *     Šimon Lukašík
 */
#ifndef OSCAP_SOURCE_H
#define OSCAP_SOURCE_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/**
 * The oscap_source is low-level structure. The oscap_source shall hold
 * information regarding SCAP file/node needed for further processing by
 * OpenSCAP library.
 *
 * The oscap_source may refer to a DataStream, a component of datastream,
 * an XCCDF or OVAL file, or any other SCAP or SCE file.
 *
 * The oscap_source is primarily focused to solve problems regarding parsing
 * and serialization of SCAP files. The structure shall not know much about
 * relation to other sources. The relations between sources should be
 * delegated to oscap_source_set.
 *
 * The oscap_source keeps track of its origin (i.e. XCCDF file may originate
 * by openning an XCCDF file, extracting XCCDF section from DataStream or
 * by evaluation.
 *
 * If oscap_source originated from DataStream there wil be other oscap_sources
 * which will keep track of the datastream descendants.
 *
 * The oscap_source is lazy structure, it only does its job when it has to.
 * The structure caches data whenever it is feasible.
 */
struct oscap_source;

/**
 * Create new oscap_source from filename. In the future this should be
 * the only function in the OpenSCAP library which will take in a path
 * to filename.
 * @param filepath Path to the file on a disk
 * @returns newly created oscap_source structure
 */
struct oscap_source *oscap_source_new_from_file(const char *filepath);

/**
 * Dispose oscap_source structure. This will dispose all the
 * children oscap_sources as well.
 * @param source Resource to dispose
 */
void oscap_source_free(struct oscap_source *source);

#endif
