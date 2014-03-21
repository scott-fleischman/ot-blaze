#import <iostream>
#import <vector>
#import <ot-blaze.h>

#import <CoreFoundation/CoreFoundation.h>
#import <CoreText/CoreText.h>

std::vector<CTFontTableTag> ConvertCFArrayToVector(CFArrayRef texts)
{
	CFIndex textCount = CFArrayGetCount(texts);
	std::vector<CTFontTableTag> results;
	results.reserve(textCount);
	for (CFIndex index = 0; index < textCount; ++index)
	{
		CTFontTableTag tag = (CTFontTableTag) (uintptr_t) CFArrayGetValueAtIndex(texts, index);
		results.push_back(tag);
	}
	return results;
}

int main(int argc, const char * argv[])
{
	CFStringRef fontName = CFStringCreateWithCString(NULL, "Helvetica", kCFStringEncodingASCII);
	CTFontRef font = CTFontCreateWithName(fontName, 12.0, NULL);
	
	unsigned unitsPerEm = CTFontGetUnitsPerEm(font);
	CFArrayRef fontTableNames = CTFontCopyAvailableTables(font, kCTFontTableOptionNoOptions);
	
	auto tableTags = ConvertCFArrayToVector(fontTableNames);
	std::cout << "tagCount: " << tableTags.size() << std::endl;
	std::cout << std::hex << "tags[0]: " << tableTags[0] << std::endl;
	
	auto table = CTFontCopyTable(font, kCTFontTableHhea, kCTFontTableOptionNoOptions);
	
	const uint8_t * data = CFDataGetBytePtr(table);
	auto raw = reinterpret_cast<const uint32_t *>(data);
	auto vraw = ot::BigEndianToLittleEndian(*raw);
	auto sraw = static_cast<int32_t>(vraw);
	ot::fixed16d16_t value { sraw };
	std::cout << "result: " << value.integer() << std::endl;
	
	CFRelease(table);
	CFRelease(fontTableNames);
	CFRelease(font);
	CFRelease(fontName);
	
	std::cout << "unitsPerEm = " << unitsPerEm << std::endl;
	
	return 0;
}
