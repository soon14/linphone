/*
 * clonable-object.h
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef _CLONABLE_OBJECT_H_
#define _CLONABLE_OBJECT_H_

#include "object-head.h"
#include "property-container.h"

// =============================================================================

LINPHONE_BEGIN_NAMESPACE

/*
 * Clonable Object of Linphone. Generally it's just a data object with no
 * intelligence.
 */
class LINPHONE_PUBLIC ClonableObject : public PropertyContainer {
	L_OBJECT;

public:
	virtual ~ClonableObject ();

protected:
	// Use a new ClonableObjectPrivate without owner.
	explicit ClonableObject (ClonableObjectPrivate &p);

	// If you want share an existing ClonableObjectPrivate, call this function.
	explicit ClonableObject (const ClonableObjectPrivate &p);

	// Change the ClonableObjectPrivate, it can be shared.
	void setRef (const ClonableObjectPrivate &p);

	ClonableObjectPrivate *mPrivate = nullptr;

private:
	L_DECLARE_PRIVATE(ClonableObject);

	// Yeah, it's a `ClonableObject` that cannot be copied.
	// Only inherited classes must implement copy.
	L_DISABLE_COPY(ClonableObject);
};

LINPHONE_END_NAMESPACE

#endif // ifndef _CLONABLE_OBJECT_H_
