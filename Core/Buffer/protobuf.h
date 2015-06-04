//#ifndef XSE_PROTOBUF_CORE_H
//#define XSE_PROTOBUF_CORE_H 1
//
//#define PROTOBUF_SUPPORT 1
//
//#ifdef PROTOBUF_SUPPORT
//
//namespace XSE {
//	namespace ProtoBuf {
//
//		class Token;
//
//		class MessgeStructPaser{
//		private:
//			char* bytes;
//		public:
//			MessgeStructPaser(const char* bytes);
//			virtual ~MessgeStructPaser(void);
//			Token getNextToken();
//		};
//
//		class Token{
//		public:
//			enum Type{
//				ROOT = 0x00,
//				NUMBER = 0x02,
//				ARRAY = 0x04,
//				KEY_VALUE = 0x08,
//				STRING = 0x16,
//			};
//
//		public:
//			Type GetType();
//
//		private:
//			Type m_type;
//		};
//
//		class Map{
//		private:
//			char * m_key;
//			void * m_value;
//
//			Map(const char* key, void* value);
//			virtual ~Map();
//			static void Make(const char* key, void* value);
//
//		};
//
//		class LanguageSupports{
//		public:
//			enum Type{
//				C = 0x01,
//			};
//
//			virtual int generateBaseClass() = 0;
//			virtual int generateType() = 0;
//		};
//	}
//}
//
//#endif
//
//#endif//(end XSE_PROTOBUF_CORE_H)