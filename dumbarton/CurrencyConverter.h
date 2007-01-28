//
//  CurrencyConverter.h
//  CurrencyConverter
//
//  Created by R. Tyler Ballance on 1/28/07.
//  Copyright 2007 bleep. LLC. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Dumbarton/Dumbarton.h>

@interface CurrencyConverter : DBMonoObjectRepresentation {

}

- (float)exchangeCurrency:(float)money fromCurrency:(NSString *)country1 toCurrency:(NSString *)country2;

@end
