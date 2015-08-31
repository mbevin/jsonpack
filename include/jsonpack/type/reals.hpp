/**
 *  Jsonpack - Reals traits for json operations
 *
 *  Copyright (c) 2015 Yadiel Martinez Gonlazez <ymglez2015@gmail.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef JSONPACK_REALS_HPP
#define JSONPACK_REALS_HPP

#include "jsonpack/type/json_traits_base.hpp"


JSONPACK_API_BEGIN_NAMESPACE
TYPE_BEGIN_NAMESPACE

//-------------------------- FLOAT --------------------------------
template<>
struct json_traits<float>
{

    static void append(buffer &json, const char *key, const float &value)
    {
        util::json_builder::append_real(json, key, value);
    }

    static void append(buffer &json, const float &value)
    {
        util::json_builder::append_real(json, value);
    }
};

template<>
struct json_traits<float&>
{
    static void extract(const object_t &json, char* json_ptr, const char *key, const std::size_t &len, float &value)
    {
        jsonpack::key k;
        k._bytes = len;
        k._ptr = key;

        object_t::const_iterator found = json.find(k);
        if( found != json.end() )    // exist the current key
        {
            extract(found->second, json_ptr, value);
        }
    }

    static void extract(const jsonpack::value &v, char* json_ptr, float &value)
    {
        if(v._field == _POS)
        {
            position p = v._pos;
            char * str_value = json_ptr+p._pos;   //pointing to the start

            char buffer[DOUBLE_MAX_DIGITS + 1];
            memcpy(buffer, str_value, p._count);
            buffer[p._count] = '\0';        //null-terminated

            value = atof( buffer );

        }
        else
        {
            //type error
        }
    }

};

//-------------------------- DOUBLE --------------------------------
template<>
struct json_traits<double>
{
    static void append(buffer &json, const char *key, const double &value)
    {
        util::json_builder::append_real(json, key, value);
    }

    static void append(buffer &json, const double &value)
    {
        util::json_builder::append_real(json, value);
    }
};

template<>
struct json_traits<double&>
{
    static void extract(const object_t &json, char* json_ptr, const char *key, const std::size_t &len, double &value)
    {
        jsonpack::key k;
        k._bytes = len;
        k._ptr = key;

        object_t::const_iterator found = json.find(k);
        if( found != json.end() )    // exist the current key
        {
            extract(found->second, json_ptr, value);
        }
    }

    static void extract(const jsonpack::value &v, char* json_ptr, double &value)
    {
        if(v._field == _POS)
        {
            position p = v._pos;
            char * str_value = json_ptr+p._pos;   //pointing to the start

            char buffer[DOUBLE_MAX_DIGITS + 1];
            memcpy(buffer, str_value, p._count);
            buffer[p._count] = '\0';        //null-terminated

            value = atof( buffer );
        }
        else
        {
            //type error
        }

    }

};

JSONPACK_API_END_NAMESPACE //type
JSONPACK_API_END_NAMESPACE //jsonpack

#endif // JSONPACK_REALS_HPP

