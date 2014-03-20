#import <iostream>
#import <ot-blaze.h>

#import <CoreFoundation/CoreFoundation.h>
#import <CoreText/CoreText.h>

int main(int argc, const char * argv[])
{
	CFStringRef fontName = CFStringCreateWithCString(NULL, "Helvetica", kCFStringEncodingASCII);
	CTFontRef font = CTFontCreateWithName(fontName, 14.0, NULL);
	
	unsigned unitsPerEm = CTFontGetUnitsPerEm(font);
	
	CFRelease(font);
	CFRelease(fontName);
	
	ot_blaze x;
	x.HelloWorld("Hi from ot-blaze!");
	
	std::cout << "unitsPerEm = " << unitsPerEm << std::endl;
	
	return 0;
}
