//
//  ExchangeController.h
//  CurrencyConverter
//
//  Created by R. Tyler Ballance on 1/28/07.
//  Copyright 2007 bleep. LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "CurrencyConverter.h"

@interface ExchangeController : NSObject {
	IBOutlet NSPopUpButton *firstCountry;
	IBOutlet NSPopUpButton *secondCountry;
	IBOutlet NSTextField *inputField;
	IBOutlet NSTextField *outputField;
	
	CurrencyConverter *converter;
}

- (IBAction)exchange:(id)sender;

@end
