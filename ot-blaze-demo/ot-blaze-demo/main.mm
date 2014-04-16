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
	
	const void * data = CFDataGetBytePtr(table);
	const ot::data_type::Fixed * tableVersionNumber = static_cast<const ot::data_type::Fixed *>(data);
	std::cout << "tableVersionNumber.integer = " << std::hex << tableVersionNumber->GetInteger() << std::endl;
	std::cout << "tableVersionNumber.fraction = " << std::hex << tableVersionNumber->GetFraction() << std::endl;
	
	CFRelease(table);
	CFRelease(fontTableNames);
	CFRelease(font);
	CFRelease(fontName);
	
	std::cout << "unitsPerEm = " << unitsPerEm << std::endl;
	
	return 0;
}
