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
	MonoString *str1 = [country1 monoString];
	MonoString *str2 = [country2 monoString];
	
	MonoObject *rateObj = [self invokeMethod:"getRate" withNumArgs:2,str1,str2];

	NSString *rateStr = [NSString stringWithMonoString:DBMonoObjectInvoke(rateObj,"ToString",0,NULL)];

	NSLog(@"Converting %f at the rate: %@", money, rateStr);
	
	return (money * [rateStr floatValue]);
}


@end
