#ifndef _SYSTEM_GUID_H_
#define _SYSTEM_GUID_H_

#include "System/Object.h"
#include "System/String.h"
#include "System/TypeDefBString.h"

namespace Aspose {
	namespace Cells {
		namespace System {

			class ASPOSE_CELLS_API Guid : public Object
			{
			private:
				enum GuidStyles
				{
					None = 0,
					AllowParenthesis = 1,
					AllowBraces = 2,
					AllowDashes = 4,
					AllowHexPrefix = 8,
					RequireParenthesis = 16,
					RequireBraces = 32,
					RequireDashes = 64,
					RequireHexPrefix = 128,
					HexFormat = 160,
					NumberFormat = 0,
					DigitFormat = 64,
					BraceFormat = 96,
					ParenthesisFormat = 80,
					Any = 15
				};

			public:
				Guid();
				Guid(intrusive_ptr<BString> bytes);
				Guid(StringPtr str);
				virtual ~Guid();

				static intrusive_ptr<Guid> Empty;// = NEW Guid();
				int32_t CompareTo(ObjectPtr value);
				//int32_t CompareTo(intrusive_ptr<Guid> guid);
				//int32_t CompareTo(Guid* guid);
				virtual bool Equals(ObjectPtr o);
				bool Equals(intrusive_ptr<Guid> guid);
				virtual int32_t GetHashCode();
				virtual StringPtr ToString();
				StringPtr ToString(StringPtr& format);

				bool operator == (const Guid& g) const {
					return _a == g._a && _b == g._b && _c == g._c && _d == g._d && _e == g._e && _f == g._f && _g == g._g && _h == g._h && _i == g._i && _j == g._j && _k == g._k;
				}
				bool operator != (const Guid& g) const {
					return !(*this == g);
				}

				intrusive_ptr<BString> ToByteArray();

				static intrusive_ptr<Guid> NewGuid();
				static intrusive_ptr<Guid> Parse(StringPtr input);
				static intrusive_ptr<Guid> ParseExact(StringPtr input, StringPtr format);
				static bool TryParse(StringPtr input, intrusive_ptr<Guid> result);
				static bool TryParseExact(StringPtr input, StringPtr format, intrusive_ptr<Guid> result);
				//for test
				bool CheckGuid(int32_t va, int16_t vb, int16_t vc, uint8_t vd, uint8_t ve,
					uint8_t vf, uint8_t vg, uint8_t vh, uint8_t vi, uint8_t vj, uint8_t vk);

			private:
				static int32_t HexsToChars(int8_t* guidChars, int32_t offset, int32_t a, int32_t b);
				static int32_t HexsToChars(int8_t* guidChars, int32_t offset, int32_t a, int32_t b, bool hex);
				static int8_t HexToChar(int32_t a);
				static bool StringToInt(char* str, int32_t requiredLength, int32_t flags, int32_t& result);
				static bool StringToInt(char* str, int32_t& parsePos, int32_t requiredLength, int32_t flags, int32_t& result);
				static bool StringToInt(char* str, int32_t* parsePos, int32_t requiredLength, int32_t flags, int32_t& result);
				static bool StringToLong(char* str, int32_t flags, int64_t& result);
				static bool StringToLong(char* str, int32_t& parsePos, int32_t flags, int64_t& result);
				static bool StringToLong(char* str, int32_t* parsePos, int32_t flags, int64_t& result);
				static bool StringToShort(char* str, int32_t requiredLength, int32_t flags, int16_t& result);
				static bool StringToShort(char* str, int32_t& parsePos, int32_t requiredLength, int32_t flags, int16_t& result);
				static bool StringToShort(char* str, int32_t* parsePos, int32_t requiredLength, int32_t flags, int16_t& result);

				static int32_t StringToInt(StringPtr s, int32_t radix, int32_t flags, int32_t* currPos);
				static int64_t StringToLong(StringPtr s, int32_t radix, int32_t flags, int32_t* currPos);

				static bool TryParseGuid(StringPtr g, Guid::GuidStyles flags, Guid* result);
				static bool TryParseGuidWithDashes(StringPtr guidString, Guid* result);
				static bool TryParseGuidWithNoStyle(StringPtr guidString, Guid* result);

				int32_t GetResult(uint32_t me, uint32_t them);

			private:
				int32_t _a;
				int16_t _b;
				int16_t _c;
				uint8_t _d;
				uint8_t _e;
				uint8_t _f;
				uint8_t _g;
				uint8_t _h;
				uint8_t _i;
				uint8_t _j;
				uint8_t _k;

			};
			typedef intrusive_ptr<Guid> GuidPtr;
		}
	}
}	// namespace System

#endif	// _SYSTEM_GUID_H_