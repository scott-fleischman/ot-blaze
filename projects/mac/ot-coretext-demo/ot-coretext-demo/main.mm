#import <iostream>
#import <vector>
#import <ot/tables.h>

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
	std::cout << "CT unitsPerEm = " << unitsPerEm << std::endl;
	CFArrayRef fontTableNames = CTFontCopyAvailableTables(font, kCTFontTableOptionNoOptions);
	
	auto tableTags = ConvertCFArrayToVector(fontTableNames);
	std::cout << "tagCount: " << tableTags.size() << std::endl;
	std::cout << "tags[0]: " << std::hex << tableTags[0] << std::dec << std::endl;
	
	auto ctHhea = CTFontCopyTable(font, kCTFontTableHhea, kCTFontTableOptionNoOptions);
	const void * hheaData = CFDataGetBytePtr(ctHhea);
	const ot::table::hhea * hhea = static_cast<const ot::table::hhea *>(hheaData);
	std::cout << "hhea.tableVersionNumber.integer = " << hhea->tableVersionNumber.GetInteger() << std::endl;
	std::cout << "hhea.tableVersionNumber.fraction = " << hhea->tableVersionNumber.GetFraction() << std::endl;
	std::cout << "hhea.ascender = " << hhea->ascender.GetValue() << std::endl;
	std::cout << "hhea.descender = " << hhea->descender.GetValue() << std::endl;
	std::cout << "hhea.numberOfHMetrics = " << hhea->numberOfHMetrics.GetValue() << std::endl;
	CFRelease(ctHhea);
	
	auto ctHead = CTFontCopyTable(font, kCTFontTableHead, kCTFontTableOptionNoOptions);
	const void * headData = CFDataGetBytePtr(ctHead);
	const ot::table::head * head = static_cast<const ot::table::head *>(headData);
	std::cout << "head.tableVersionNumber.integer = " << head->tableVersionNumber.GetInteger() << std::endl;
	std::cout << "head.tableVersionNumber.fraction = " << head->tableVersionNumber.GetFraction() << std::endl;
	std::cout << "head.unitsPerEm = " << head->unitsPerEm.GetValue() << std::endl;
	std::cout << "head.magicNumber = " << std::hex << head->magicNumber.GetValue() << std::dec << std::endl;
	std::cout << "head.xMin = " << head->xMin.GetValue() << std::endl;
	std::cout << "head.yMin = " << head->yMin.GetValue() << std::endl;
	std::cout << "head.xMax = " << head->xMax.GetValue() << std::endl;
	std::cout << "head.yMax = " << head->yMax.GetValue() << std::endl;
	CFRelease(ctHead);
	
	CFRelease(fontTableNames);
	CFRelease(font);
	CFRelease(fontName);
	
	return 0;
}
