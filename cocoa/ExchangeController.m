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
	[progress setUsesThreadedAnimation:TRUE];
	
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(exchangeFinished:) name:@"Exchange Finished" object:nil];
}

- (IBAction)exchange:(id)sender
{
	if (converter == nil)
		converter = [[CurrencyConverter alloc] init];
	
	float money = [inputField floatValue];
			
	[progress setHidden:FALSE];
	[progress startAnimation:self];
	
	double result = [converter exchangeCurrency:money fromCurrency:[[firstCountry selectedItem] title] 
									 toCurrency:[[secondCountry selectedItem] title]];
	
	if (result != 0.0)
		[outputField setDoubleValue:result];
	
	[progress stopAnimation:self];
	[progress setHidden:TRUE];
	
	//	XXX: Dumbarton seems to crash the Mono runtime if we call this inside a thread
	//		I have a feeling that it is related to our MonoController being inside this thread
	
	//	The webservice will block, so we'll spin up a thread to prevent UI blockage
	//[NSThread detachNewThreadSelector:@selector(exchangeMethod:) toTarget:self withObject:[NSNumber numberWithDouble:money]];
}

- (void)exchangeMethod:(NSNumber *)number
{
	double result = [converter exchangeCurrency:[number doubleValue] fromCurrency:[[firstCountry selectedItem] title] 
										toCurrency:[[secondCountry selectedItem] title]];
	NSLog(@"exchangeMethod: %f", result);
	
	[[NSNotificationCenter defaultCenter] postNotificationName:@"Exchange Finished" object:[NSNumber numberWithDouble:result]];
}

- (void)exchangeFinished:(NSNotification *)notification
{
	double result = [[notification object] doubleValue];
	
	if (result != 0.0)
		[outputField setDoubleValue:result];
	
	[progress stopAnimation:self];
	[progress setHidden:TRUE];
}


@end
