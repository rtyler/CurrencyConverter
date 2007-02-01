//
//  CurrencyConverter.m
//  CurrencyConverter
//
//  Created by R. Tyler Ballance on 1/28/07.
//  Copyright 2007 bleep. LLC. All rights reserved.
//

#import "CurrencyConverter.h"
#import "MonoController.h"

@implementation CurrencyConverter

+ (MonoClass *)monoClass {
	MonoClass *monoClass = [DBMonoEnvironment monoClassWithName:"Bleep.CurrencyExchangeService" 
											fromAssembly:[MonoController converterAssembly]];
	
	return monoClass;
}

- (float)exchangeCurrency:(float)money fromCurrency:(NSString *)country1 toCurrency:(NSString *)country2
{
	NSLog(@"Converting %f from %@ to %@ currency", money, country1, country2);
	MonoString *str1 = [[NSString stringWithString:@"usa"] monoString];
	MonoString *str2 = [[NSString stringWithString:@"uk"] monoString];
	
	MonoObject *rateObj = [self invokeMethod:"getRate" withNumArgs:2,str1,str2];

	// Invoke the rateObj.ToString() to get a MonoString *
	NSString *rateStr = [NSString stringWithMonoString:(MonoString *)(DBMonoObjectInvoke(rateObj,"ToString",0,NULL))];

	NSLog(@"Converting %f at the rate: %@", money, rateStr);\
	
	if (rateStr != nil)
		return (money * [rateStr floatValue]);
	else
		return 0.0;
}


@end
