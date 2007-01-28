//
//  MonoController.m
//  CurrencyConverter
//
//  Created by R. Tyler Ballance on 1/28/07.
//  Copyright 2007 bleep. LLC. All rights reserved.
//

#import "MonoController.h"

static MonoAssembly *converterAssembly = NULL;

@implementation MonoController

+ (void)initialize {
	if([self class] != [MonoController class])
		return;
	
	DBMonoEnvironment *monoEnvironment = [DBMonoEnvironment defaultEnvironment];
	
	NSString *libraryPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"Contents/Libraries"];
	NSString *converterAssemblyPath = [libraryPath stringByAppendingPathComponent:@"CurrencyExchangeService.dll"];
	
	converterAssembly = [monoEnvironment openAssemblyWithPath:converterAssemblyPath];
	
	NSLog(@"CurrencyExchangeService Assembly Path: %@", converterAssemblyPath);
}

+ (MonoAssembly *)converterAssembly {
	return (converterAssembly);
}

@end
