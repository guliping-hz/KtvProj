// gameswf_value.h	-- Thatcher Ulrich <tu@tulrich.com> 2003

// This source code has been donated to the Public Domain.  Do
// whatever you want with it.

// ActionScript value type.


#ifndef GAMESWF_VALUE_H
#define GAMESWF_VALUE_H

#include "base/container.h"
#include "gameswf/gameswf.h"	// for ref_counted
#include <wchar.h>

namespace gameswf
{
	struct fn_call;
	struct as_c_function;
	struct as_function;
	struct as_object;
	struct as_environment;

	bool string_to_number(int* result, const char* str, int base = 10);
	bool string_to_number(double* result, const char* str);

	typedef void (*as_c_function_ptr)(const fn_call& fn);

	// helper, used in as_value
	struct as_property : public ref_counted
	{
		gc_ptr<as_function>	m_getter;
		gc_ptr<as_function>	m_setter;

		as_property(const as_value& getter,	const as_value& setter);
		~as_property();
	
		void	set(as_object* target, const as_value& val);
		void	get(as_object* target, as_value* val) const;
		void	get(const as_value& primitive, as_value* val) const;
	};

	struct as_value
	{
		// flags defining the level of protection of a value
		enum value_flag
		{
			DONT_ENUM = 0x01,
			DONT_DELETE = 0x02,
			READ_ONLY = 0x04
		};

		private:

		enum type
		{
			UNDEFINED,
			BOOLEAN,
			NUMBER,
			STRING,
			OBJECT,
			PROPERTY
		};
		type	m_type;

		mutable tu_string	m_string;
		union
		{
			double m_number;
			bool m_bool;
		};

		gc_ptr<as_object> m_object;
		gc_ptr<as_object> m_property_target;
		gc_ptr<as_property> m_property;
		
		// Numeric flags
		mutable int m_flags;

	public:

		// constructors
		as_value();
		as_value(const as_value& v);
		as_value(const char* str);
		as_value(const wchar_t* wstr);
		as_value(bool val);
		as_value(int val);
		as_value(float val);
		as_value(double val);
		as_value(as_object* obj);
		as_value(as_c_function_ptr func);
		as_value(as_s_function* func);
		as_value(const as_value& getter, const as_value& setter);

		~as_value() { drop_refs(); }

		// Useful when changing types/values.
		void	drop_refs();

		// for debuging
		const char*	to_xstring() const;

		const char*	to_string() const;
		const tu_string&	to_tu_string() const;
		const tu_stringi&	to_tu_stringi() const;
		double	to_number() const;
		int	to_int() const { return (int) to_number(); };
		float	to_float() const { return (float) to_number(); };
		bool	to_bool() const;
		as_function*	to_function() const;
		as_object*	to_object() const;
		as_property*	to_property() const;

		// These set_*()'s are more type-safe; should be used
		// in preference to generic overloaded set().  You are
		// more likely to get a warning/error if misused.
		void	set_tu_string(const tu_string& str);
		void	set_string(const char* str);
		void	set_double(double val);
		void	set_bool(bool val);
		void	set_int(int val) { set_double(val); }
		void	set_nan() { set_double(get_nan()); }
		void	set_as_object(as_object* obj);
		void	set_as_c_function(as_c_function_ptr func);
		void	set_undefined() { drop_refs(); m_type = UNDEFINED; }
		void	set_null() { set_as_object(NULL); }

		void	set_property(const as_value& val);
		void	get_property(as_value* val) const;
		void	get_property(const as_value& primitive, as_value* val) const;
		const as_object*	get_property_target() const;  // for debugging
		void	set_property_target(as_object* new_target);

		void	operator=(const as_value& v);
		bool	operator==(const as_value& v) const;
		bool	operator!=(const as_value& v) const;
		bool	operator<(double v) const { return to_number() < v; }
		void	operator+=(double v) { set_double(to_number() + v); }
		void	operator-=(double v) { set_double(to_number() - v); }
		void	operator*=(double v) { set_double(to_number() * v); }
		void	operator/=(double v) { set_double(to_number() / v); }  // @@ check for div/0
		void	operator&=(int v) { set_int(int(to_number()) & v); }
		void	operator|=(int v) { set_int(int(to_number()) | v); }
		void	operator^=(int v) { set_int(int(to_number()) ^ v); }
		void	shl(int v) { set_int(int(to_number()) << v); }
		void	asr(int v) { set_int(int(to_number()) >> v); }
		void	lsr(int v) { set_int((Uint32(to_number()) >> v)); }

		bool is_function() const;
		inline bool is_bool() const { return m_type == BOOLEAN; }
		inline bool is_string() const { return m_type == STRING; }
		inline bool is_number() const { return m_type == NUMBER && isnan(m_number) == false; }
		inline bool is_object() const { return m_type == OBJECT; }
		inline bool is_property() const { return m_type == PROPERTY; }
		inline bool is_null() const { return m_type == OBJECT && m_object == NULL; }
		inline bool is_undefined() const { return m_type == UNDEFINED; }

		const char* type_of() const;
		bool is_instance_of(const as_function* constructor) const;
		bool find_property(const tu_string& name, as_value* val);
		bool find_property_owner(const tu_string& name, as_value* val);

		// flags
		inline bool is_enum() const { return m_flags & DONT_ENUM ? false : true; }
		inline bool is_readonly() const { return m_flags & READ_ONLY ? true : false; }
		inline bool is_protected() const { return m_flags & DONT_DELETE ? true : false; }
		inline int get_flags() const { return m_flags; }
		inline void set_flags(int flags) const  { m_flags = flags; }

		static bool abstract_equality_comparison( const as_value & first, const as_value & second );
		static as_value abstract_relational_comparison( const as_value & first, const as_value & second );

	};

}


#endif
