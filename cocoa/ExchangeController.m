//
//  ExchangeController.m
//  CurrencyConverter
//
//  Created by R. Tyler Ballance on 1/28/07.
//  Copyright 2007 bleep. LLC. All rights reserved.
//

#import "ExchangeController.h"

@implementation ExchangeController

- (void)awakeFromNib 
{
}

- (IBAction)exchange:(id)sender
{
	if (converter == nil)
		converter = [[CurrencyConverter alloc] init];
	
	NSString *country1 = [[firstCountry selectedItem] title];
	NSString *country2 = [[secondCountry selectedItem] title];
	float money = [inputField floatValue];
			
	NSString *convertedMoney = [NSString stringWithFormat:@"%f",[converter exchangeCurrency:money fromCurrency:country1 toCurrency:country2]];
	
	[outputField setStringValue:convertedMoney];
}	

@end
