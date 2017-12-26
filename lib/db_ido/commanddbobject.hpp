/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2017 Icinga Development Team (https://www.icinga.com/)  *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#pragma once

#ifndef COMMANDDBOBJECT_H
#define COMMANDDBOBJECT_H

#include "db_ido/dbobject.hpp"
#include "base/configobject.hpp"

namespace icinga
{

/**
 * A Command database object.
 *
 * @ingroup ido
 */
class CommandDbObject : public DbObject
{
public:
	DECLARE_PTR_TYPEDEFS(CommandDbObject);

	CommandDbObject(const DbType::Ptr& type, const String& name1, const String& name2);

	virtual Dictionary::Ptr GetConfigFields(void) const override;
	virtual Dictionary::Ptr GetStatusFields(void) const override;
};

}

#endif /* COMMANDDBOBJECT_H */
