/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_SINGLETON_H
#define MANGOS_SINGLETON_H

/**
 * @brief class Singleton
 */

#include "BaseCode/CreationPolicy.h"
#include "ThreadingModel.h"
#include "ObjectLifeTime.h"

template
    <
    typename T,
    class ThreadingModel =  SingleThreaded<T>,
    class CreatePolicy =  tq::OperatorNew<T>,
    class LifeTimePolicy =  ObjectLifeTime<T>
    >
    class Singleton
{
    public:
        static T& Instance();

    protected:
        Singleton() {};

    private:

        // Prohibited actions...this does not prevent hijacking.
        Singleton(const Singleton &);
        Singleton& operator=(const Singleton &);

        // Singleton Helpers
        static void DestroySingleton();

        // data structure
        typedef typename ThreadingModel::Lock Guard;
        static T *si_instance;
        static bool si_destroyed;
};
#endif
