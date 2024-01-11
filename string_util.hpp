#pragma once
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

namespace cpp {
	namespace detail {
		// -------------------------------------------------------------------
		// Shared Type.
		// -------------------------------------------------------------------
		template<typename _Elem>
		struct Space_v {
			static_assert(!std::_Is_character<_Elem>::value, "not support type.");
		};
		template<>
		struct Space_v<char> {
			static const char value = ' ';
		};
		template<>
		struct Space_v<wchar_t> {
			static const wchar_t value = L' ';
		};
		template<typename _Elem>
		struct To_Lower_Fn {
			static_assert(!std::_Is_character<_Elem>::value, "not support type.");
		};
		template<>
		struct To_Lower_Fn<char> {
			auto operator()(char ch) {
				return std::tolower(ch);
			}
		};
		template<>
		struct To_Lower_Fn<wchar_t> {
			auto operator()(wchar_t ch) {
				return towlower(ch);
			}
		};
		template<typename _Elem>
		struct To_Upper_Fn {
			static_assert(!std::_Is_character<_Elem>::value, "not support type.");
		};
		template<>
		struct To_Upper_Fn<char> {
			auto operator()(char ch) {
				return std::toupper(ch);
			}
		};
		template<>
		struct To_Upper_Fn<wchar_t> {
			auto operator()(wchar_t ch) {
				return towupper(ch);
			}
		};
		// -------------------------------------------------------------------
		// Arg Parsing.
		// -------------------------------------------------------------------
		template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		struct StringArgGroup {
			std::vector<std::basic_string<_Elem, _Traits, _Alloc>> result;
			size_t totalCapacity;
		};
		template<class _Traits = std::char_traits<char>, class _Alloc = std::allocator<char>>
		inline auto ReadArgTo(StringArgGroup<char, _Traits, _Alloc>* group, int arg) {
			assert(group);
			auto value = std::to_string(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<char>, class _Alloc = std::allocator<char>>
		inline auto ReadArgTo(StringArgGroup<char, _Traits, _Alloc>* group, long arg) {
			assert(group);
			auto value = std::to_string(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<char>, class _Alloc = std::allocator<char>>
		inline auto ReadArgTo(StringArgGroup<char, _Traits, _Alloc>* group, float arg) {
			assert(group);
			auto value = std::to_string(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<char>, class _Alloc = std::allocator<char>>
		inline auto ReadArgTo(StringArgGroup<char, _Traits, _Alloc>* group, double arg) {
			assert(group);
			auto value = std::to_string(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<wchar_t>, class _Alloc = std::allocator<wchar_t>>
		inline auto ReadArgTo(StringArgGroup<wchar_t, _Traits, _Alloc>* group, int arg) {
			assert(group);
			auto value = std::to_wstring(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<wchar_t>, class _Alloc = std::allocator<wchar_t>>
		inline auto ReadArgTo(StringArgGroup<wchar_t, _Traits, _Alloc>* group, long arg) {
			assert(group);
			auto value = std::to_wstring(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<wchar_t>, class _Alloc = std::allocator<wchar_t>>
		inline auto ReadArgTo(StringArgGroup<wchar_t, _Traits, _Alloc>* group, float arg) {
			assert(group);
			auto value = std::to_wstring(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<class _Traits = std::char_traits<wchar_t>, class _Alloc = std::allocator<wchar_t>>
		inline auto ReadArgTo(StringArgGroup<wchar_t, _Traits, _Alloc>* group, double arg) {
			assert(group);
			auto value = std::to_wstring(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		inline auto ReadArgTo(StringArgGroup<_Elem, _Traits, _Alloc>* group, _Elem arg) {
			assert(group);
			auto value = std::basic_string<_Elem, _Traits, _Alloc>(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		inline auto ReadArgTo(StringArgGroup<_Elem, _Traits, _Alloc>* group, const _Elem* arg) {
			assert(group);
			auto value = std::basic_string<_Elem, _Traits, _Alloc>(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		inline auto ReadArgTo(StringArgGroup<_Elem, _Traits, _Alloc>* group, _Elem* arg) {
			assert(group);
			auto value = std::basic_string<_Elem, _Traits, _Alloc>(arg);
			group->result.push_back(value);
			group->totalCapacity += value.size();
		}

		template<typename Arg, typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		inline auto ReadArg(StringArgGroup<_Elem, _Traits, _Alloc>* group, Arg arg) {
			assert(group);
			ReadArgTo(group, arg);
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename Tuple, size_t _Index>
		inline auto ReadArgInTuple(StringArgGroup<_Elem, _Traits, _Alloc>* group, const Tuple& tuple) {
			assert(group);
			static_assert(std::tuple_size<Tuple>::value > _Index, "Tuple must be the large than _INDEX.");
			ReadArg(group, std::get<_Index>(tuple));
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename Tuple, size_t ...Is>
		inline auto ReadArgsAtIndex(StringArgGroup<_Elem, _Traits, _Alloc>* group, const Tuple& tuple, std::index_sequence<Is...>) {
			assert(group);
			auto seq = { ((ReadArgInTuple<_Elem, _Traits, _Alloc, Tuple, Is>(group, tuple)), 0)... };
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename Tuple>
		inline auto ReadArgsIndexsequence(StringArgGroup<_Elem, _Traits, _Alloc>* group, const Tuple& tuple) {
			assert(group);
			ReadArgsAtIndex<_Elem>(group, tuple, std::make_index_sequence<std::tuple_size<Tuple>::value>{});
		}
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename ...Args>
		inline auto ArgsToTuple(StringArgGroup<_Elem, _Traits, _Alloc>* group, Args&&... args) {
			assert(group);
			std::tuple<Args&...> tuple{ std::forward<Args&>(args)... };
			ReadArgsIndexsequence<_Elem>(group, tuple);
		}
		// -------------------------------------------------------------------
		// Format.
		// -------------------------------------------------------------------
		template<typename _Elem>
		struct StringFormatSegment {
			_Elem* begin;
			_Elem* end;
			_Elem* next;
			size_t index;
			bool ok;
		};
		template<typename _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
		auto FormatString(const _Elem* format, _Elem* begin, size_t index) {
			StringFormatSegment<_Elem> result{};
			_Elem* pstr = (_Elem*)begin;
			_Elem ch = *pstr;
			result.begin = pstr;
			// 1. find '{'.
			while (ch && ch != '{') {
				ch = *++pstr;
			}
			result.end = pstr;
			if (!ch) {
				return result;
			}
			// 2. has index?
			ch = *++pstr;
			result.index = index;
			if (ch && ch >= '0' && ch <= '9') {
				int i = ch - '0';
				result.index = static_cast<size_t>(i);
				ch = *++pstr;
			}
			if (!ch) {
				return result;
			}
			// 3.. is '}'?
			if (ch != '}') {
				return result;
			}
			result.next = ++pstr;
			result.ok = true;
			return result;
		}
	}
	// -------------------------------------------------------------------
	// Trim.
	// -------------------------------------------------------------------
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void LTrim(std::basic_string<_Elem, _Traits, _Alloc>* pstring) {
		assert(pstring);
		auto& lstring = *pstring;
		auto not_space = lstring.find_first_not_of(detail::Space_v<_Elem>::value);
		lstring.erase(0, not_space);
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto LTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring) {
		std::string cstring{};
		auto not_space = rstring.find_first_not_of(detail::Space_v<_Elem>::value);
		return cstring.assign(rstring, not_space);
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void RTrim(std::basic_string<_Elem, _Traits, _Alloc>* pstring) {
		assert(pstring);
		auto& lstring = *pstring;
		auto not_space = lstring.find_last_not_of(detail::Space_v<_Elem>::value);
		lstring.erase(not_space);
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto RTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring) {
		std::string cstring{};
		auto not_space = rstring.find_last_not_of(detail::Space_v<_Elem>::value);
		return cstring.assign(rstring, 0, not_space + 1);
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void Trim(std::basic_string<_Elem, _Traits, _Alloc>* pstring) {
		assert(pstring);
		auto& lstring = *pstring;
		auto left_space = lstring.find_first_not_of(detail::Space_v<_Elem>::value);
		auto right_space = lstring.find_last_not_of(detail::Space_v<_Elem>::value);
		lstring.assign(lstring, left_space, right_space);
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto Trim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring) {
		std::string cstring{};
		auto left_space = rstring.find_first_not_of(detail::Space_v<_Elem>::value);
		auto right_space = rstring.find_last_not_of(detail::Space_v<_Elem>::value);
		cstring.assign(rstring, left_space, right_space);
		return cstring;
	}
	// -------------------------------------------------------------------
	// Split.
	// -------------------------------------------------------------------
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void Split(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, _Elem delim, std::vector< std::basic_string<_Elem, _Traits, _Alloc>>* presult) {
		auto& lresult = *presult;
		size_t begin{}, end{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			end = rstring.find_first_of(delim, begin);
			lresult.emplace_back(rstring, begin, end - begin);
			begin = end + 1;
		}
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void SplitTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, _Elem delim, std::vector< std::basic_string<_Elem, _Traits, _Alloc>>* presult) {
		auto& lresult = *presult;
		size_t begin{}, end{}, not_lspace{}, not_rspace{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			not_lspace = rstring.find_first_not_of(detail::Space_v<_Elem>::value, begin);
			end = rstring.find_first_of(delim, begin);
			not_rspace = rstring.find_last_not_of(detail::Space_v<_Elem>::value, end);
			lresult.emplace_back(rstring, not_lspace, not_rspace - not_lspace);
			begin = end + 1;
		}
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void Split(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, const _Elem* delim, std::vector< std::basic_string<_Elem, _Traits, _Alloc>>* presult) {
		auto& lresult = *presult;
		size_t begin{}, end{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			end = rstring.find_first_of(delim, begin);
			lresult.emplace_back(rstring, begin, end - begin);
			begin = end + 1;
		}
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void SplitTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, const _Elem* delim, std::vector< std::basic_string<_Elem, _Traits, _Alloc>>* presult) {
		auto& lresult = *presult;
		size_t begin{}, end{}, not_lspace{}, not_rspace{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			not_lspace = rstring.find_first_not_of(detail::Space_v<_Elem>::value, begin);
			end = rstring.find_first_of(delim, begin);
			not_rspace = rstring.find_last_not_of(detail::Space_v<_Elem>::value, end);
			lresult.emplace_back(rstring, not_lspace, not_rspace - not_lspace);
			begin = end + 1;
		}
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto Split(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, _Elem delim) {
		std::vector< std::basic_string<_Elem, _Traits, _Alloc>> lresult{};
		size_t begin{}, end{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			end = rstring.find_first_of(delim, begin);
			lresult.emplace_back(rstring, begin, end - begin);
			begin = end + 1;
		}
		return lresult;
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto SplitTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, _Elem delim) {
		std::vector< std::basic_string<_Elem, _Traits, _Alloc>> lresult{};
		size_t begin{}, end{}, not_lspace{}, not_rspace{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			not_lspace = rstring.find_first_not_of(detail::Space_v<_Elem>::value, begin);
			end = rstring.find_first_of(delim, begin);
			not_rspace = rstring.find_last_not_of(detail::Space_v<_Elem>::value, end);
			lresult.emplace_back(rstring, not_lspace, not_rspace - not_lspace);
			begin = end + 1;
		}
		return lresult;
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto Split(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, const _Elem* delim) {
		std::vector< std::basic_string<_Elem, _Traits, _Alloc>> lresult{};
		size_t begin{}, end{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			end = rstring.find_first_of(delim, begin);
			lresult.emplace_back(rstring, begin, end - begin);
			begin = end + 1;
		}
		return lresult;
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto SplitTrim(const std::basic_string<_Elem, _Traits, _Alloc>& rstring, const _Elem* delim) {
		std::vector< std::basic_string<_Elem, _Traits, _Alloc>> lresult{};
		size_t begin{}, end{}, not_lspace{}, not_rspace{};
		while (end != std::basic_string<_Elem, _Traits, _Alloc>::npos) {
			not_lspace = rstring.find_first_not_of(detail::Space_v<_Elem>::value, begin);
			end = rstring.find_first_of(delim, begin);
			not_rspace = rstring.find_last_not_of(detail::Space_v<_Elem>::value, end);
			lresult.emplace_back(rstring, not_lspace, not_rspace - not_lspace);
			begin = end + 1;
		}
		return lresult;
	}
	// -------------------------------------------------------------------
	// Lower/Upper
	// -------------------------------------------------------------------
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto ToLower(const std::basic_string<_Elem, _Traits, _Alloc>& rstring) {
		auto begin = rstring.begin();
		const auto end = rstring.end();
		std::basic_string<_Elem, _Traits, _Alloc> cstring{};
		detail::To_Lower_Fn<_Elem> fn{};

		cstring.reserve(rstring.size());
		for (; begin != end; ++begin) {
			cstring.push_back(fn(*begin));
		}
		return cstring;
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void ToLower(std::basic_string<_Elem, _Traits, _Alloc>* pstring) {
		auto& lstring = *pstring;
		auto begin = lstring.begin();
		const auto end = lstring.end();
		detail::To_Lower_Fn<_Elem> fn{};
		for (; begin != end; ++begin) {
			*begin = fn(*begin);
		}
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	auto ToUpper(const std::basic_string<_Elem, _Traits, _Alloc>& rstring) {
		auto begin = rstring.begin();
		const auto end = rstring.end();
		std::basic_string<_Elem, _Traits, _Alloc> cstring{};
		detail::To_Upper_Fn<_Elem> fn{};

		cstring.reserve(rstring.size());
		for (; begin != end; ++begin) {
			cstring.push_back(fn(*begin));
		}
		return cstring;
	}
	template <class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>>
	void ToUpper(std::basic_string<_Elem, _Traits, _Alloc>* pstring) {
		auto& lstring = *pstring;
		auto begin = lstring.begin();
		const auto end = lstring.end();
		detail::To_Upper_Fn<_Elem> fn{};
		for (; begin != end; ++begin) {
			*begin = fn(*begin);
		}
	}
	// -------------------------------------------------------------------
	// Concat
	// -------------------------------------------------------------------
	template<class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename ...Args>
	auto Concat(Args&&... args) {
		detail::StringArgGroup<_Elem, _Traits, _Alloc> group{};
		std::basic_string<_Elem, _Traits, _Alloc> value{};

		detail::ArgsToTuple(&group, std::forward<Args&>(args)...);
		value.reserve(group.totalCapacity);
		for (auto& s : group.result) {
			value.append(s);
		}
		return value;
	}
	// -----------------------------------------------------------------------
	// Join
	// -----------------------------------------------------------------------
	template<class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename ...Args>
	auto Join(_Elem delim, Args&&... args) {
		detail::StringArgGroup<_Elem, _Traits, _Alloc> group{};
		std::basic_string<_Elem, _Traits, _Alloc> value{};
		detail::ArgsToTuple(&group, std::forward<Args&>(args)...);
		auto result = group.result;
		auto size = result.size();
		if (size < 2) {
			if (size == 1) {
				return result[0];
			}
			return value;
		}
		value.reserve(group.totalCapacity + size);
		value += result[0];
		for (size_t i = 1; i < size; ++i) {
			value += delim;
			value += result[i];
		}
		return value;
	}
	template<class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, size_t _Size, typename ...Args>
	auto Join(const _Elem(*delim)[_Size], Args&&... args) {
		detail::StringArgGroup<_Elem, _Traits, _Alloc> group{};
		std::basic_string<_Elem, _Traits, _Alloc> value{};
		detail::ArgsToTuple(&group, std::forward<Args&>(args)...);
		auto result = group.result;
		auto size = result.size();
		if (size < 2) {
			if (size == 1) {
				return result[0];
			}
			return value;
		}
		value.reserve(group.totalCapacity + _Size * size);
		value += result[0];
		for (size_t i = 1; i < size; ++i) {
			value += delim;
			value += result[i];
		}
		return value;
	}
	// -----------------------------------------------------------------------
	// Format
	// -----------------------------------------------------------------------
	template<class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename ...Args>
	auto Format(const _Elem* format, Args&&... args) {
		detail::StringArgGroup<_Elem, _Traits, _Alloc> group{};
		std::basic_string<_Elem, _Traits, _Alloc> result{};
		_Elem* pstr = (_Elem*)format;
		size_t index{};
		detail::ArgsToTuple(&group, std::forward<Args&>(args)...);
		while (pstr) {
			auto segment = detail::FormatString(format, pstr, index);
			pstr = (_Elem*)segment.begin;
			_Elem _end = *segment.end;
			for (; *pstr != _end; ++pstr) {
				result.push_back(*pstr);
			}
			if (!segment.ok) {
				break;
			}
			result.append(group.result[index]);
			index = segment.index + 1;
			pstr = segment.next;
		}
		return result;
	}
	template<class _Elem, class _Traits = std::char_traits<_Elem>, class _Alloc = std::allocator<_Elem>, typename ...Args>
	auto Format(const std::basic_string<_Elem, _Traits, _Alloc>& format, Args&&... args) {
		return Format(format.c_str(), std::forward<Args&>(args)...);
	}

}