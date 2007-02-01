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
	
	IBOutlet NSProgressIndicator *progress;
	
	CurrencyConverter *converter;
	NSString *country1;
	NSString *country2;
}

- (IBAction)exchange:(id)sender;

- (void)exchangeMethod:(NSNumber *)number;
- (void)exchangeFinished:(NSNotification *)notification;

@end
