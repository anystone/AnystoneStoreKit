//
//  ASTStoreFamilyData.h
//  ASTStoreController
//
//  Created by Sean Kormilo on 11-03-15.
//  http://www.anystonetech.com

//  Copyright (c) 2011 Anystone Technologies, Inc.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "ASTStoreProductTypes.h"

@class ASTStoreFamilyData;

@protocol ASTStoreFamilyDataExpiryProtocol <NSObject>

- (void)astFamilyDataVerifySubscriptionForFamilyData:(ASTStoreFamilyData*)familyData;

@end


@interface ASTStoreFamilyData : NSObject <NSCoding, NSCopying> {}

// Creates a new instance if necessary
+ (ASTStoreFamilyData*)familyDataWithIdentifier:(NSString*)aFamilyIdentifier productType:(ASTStoreProductIdentifierType)productType;

// Only returns existing entities
+ (ASTStoreFamilyData*)familyDataWithIdentifier:(NSString*)aFamilyIdentifier;

+ (void)removeFamilyDataForIdentifier:(NSString*)aFamilyIdentifier;
- (id)initWithFamilyIdentifier:(NSString*)aFamilyIdentifier;

+ (void)setFamilyDataDelegate:(id<ASTStoreFamilyDataExpiryProtocol>)delegate;

@property (nonatomic) NSUInteger availableQuantity;
@property (readonly,copy) NSString *familyIdentifier;
@property ASTStoreProductIdentifierType type;


@property (readonly) BOOL isPurchased;
- (NSUInteger)consumeQuantity:(NSUInteger)amountToConsume;

// Base64 encoded receipt data
@property (nonatomic,copy) NSString *receipt;

// Expiry Date for a subscription - if nil then subscription is not active
@property (nonatomic,retain) NSDate *expiresDate;

@end
