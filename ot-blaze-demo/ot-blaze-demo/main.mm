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
		std::cout << "tags[" << index << "]=" << tag << std::endl;
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
	auto tags = ConvertCFArrayToVector(fontTableNames);
	
	CTFontTableTag blah = 'BASE';
	std::cout << std::hex << blah << std::endl;
	
	std::cout << "tagCount: " << tags.size() << std::endl;
	std::cout << std::hex << "tags[0]: " << tags[0] << std::endl;
	
	CFRelease(fontTableNames);
	CFRelease(font);
	CFRelease(fontName);
	
	ot_blaze x;
	x.HelloWorld("Hi from ot-blaze!");
	
	std::cout << "unitsPerEm = " << unitsPerEm << std::endl;
	
	return 0;
}
