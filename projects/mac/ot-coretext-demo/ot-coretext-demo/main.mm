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
	std::cout << "head.tableVersionNumber.integer = " << head->GetTableVersionNumberInteger() << std::endl;
	std::cout << "head.tableVersionNumber.fraction = " << head->GetTableVersionNumberFraction() << std::endl;
	std::cout << "head.unitsPerEm = " << head->GetUnitsPerEm() << std::endl;
	std::cout << "head.magicNumber = " << std::hex << head->GetMagicNumber() << std::dec << std::endl;
	std::cout << "head.xMin = " << head->GetXMin() << std::endl;
	std::cout << "head.yMin = " << head->GetYMin() << std::endl;
	std::cout << "head.xMax = " << head->GetXMax() << std::endl;
	std::cout << "head.yMax = " << head->GetYMax() << std::endl;
	CFRelease(ctHead);
	
	auto ctCmap = CTFontCopyTable(font, kCTFontTableCmap, kCTFontTableOptionNoOptions);
	const uint8_t * cmapData = CFDataGetBytePtr(ctCmap);
	ot::table::cmap_navigator cmap { cmapData };
	std::cout << "cmap.version = " << cmap.GetHeader()->GetVersion() << std::endl;
	std::cout << "cmap.numTables = " << cmap.GetHeader()->GetNumTables() << std::endl;
	for (auto & encodingRecord : cmap.GetRecords())
	{
		std::cout << "cmap encoding record.platformID = " << encodingRecord.GetPlatformID() << std::endl;
		std::cout << "cmap encoding record.encodingID = " << encodingRecord.GetEncodingID() << std::endl;
		std::cout << "cmap encoding record.offset = " << encodingRecord.GetOffset() << std::endl;
		
		std::cout << "cmap encoding record format = " << cmap.GetFormat(encodingRecord) << std::endl;
		std::cout << std::endl;
	}
	
	CFRelease(fontTableNames);
	CFRelease(font);
	CFRelease(fontName);
	
	return 0;
}
