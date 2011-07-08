//
//  ASTStoreProduct.h
//  ASTStoreController
//
//  Created by Sean Kormilo on 11-03-08.
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

@interface ASTStoreProduct : NSObject {}


+ (id)nonConsumableStoreProductWithIdentifier:(NSString*)aProductIdentifier;

+ (id)consumableStoreProductWithIdentifier:(NSString*)aProductIdentifier 
                          familyIdentifier:(NSString*)aFamilyIdentifier 
                            familyQuantity:(NSUInteger)aFamilyQuantity;

+ (id)autoRenewableStoreProductWithIdentifier:(NSString*)aProductIdentifier 
                             familyIdentifier:(NSString*)aFamilyIdentifier 
                               familyQuantity:(ASTStoreProductAutoRenewableType)aFamilyQuantity;

+ (id)storeProductWithProductIdentifier:(NSString*)aProductIdentifier 
                                   type:(ASTStoreProductIdentifierType)aType
                       familyIdentifier:(NSString*)aFamilyIdentifier
                         familyQuantity:(NSUInteger)aFamilyQuantity;

- (id)initNonConsumableStoreProductWithIdentifier:(NSString*)aProductIdentifier;

- (id)initConsumableStoreProductWithIdentifier:(NSString*)aProductIdentifier 
                          familyIdentifier:(NSString*)aFamilyIdentifier 
                            familyQuantity:(NSUInteger)aFamilyQuantity;

- (id)initAutoRenewableStoreProductWithIdentifier:(NSString*)aProductIdentifier 
                             familyIdentifier:(NSString*)aFamilyIdentifier 
                               familyQuantity:(ASTStoreProductAutoRenewableType)aFamilyQuantity;

@property (readonly) BOOL isPurchased;
@property (nonatomic,readonly,retain) NSDate *expiresDate;
@property (readonly) NSUInteger availableQuantity;
- (NSUInteger)consumeQuantity:(NSUInteger)amountToConsume;

- (void)setPurchasedQuantity:(NSUInteger)totalQuantityAvailable;


// Product identifier as specified in iTunes connect
@property (readonly) NSString *productIdentifier;

// The type of products, consumable, nonconsumable, autorenew
@property (readonly) ASTStoreProductIdentifierType type;

// Used to track consumables/AutoRenewables; Required for Consumable and AutoRenewable types
// Should match family type in iTunes connect for autorenewables
// Otherwise used to ensure that the same consumables are pegged against the right value
// assuming multiple product identifiers have differing quantities
@property (readonly) NSString *familyIdentifier;

// Used to manage increments and decrements of item quantities for consumables and autorenewables
@property  NSUInteger familyQuanity;

// Title to send back from localizedTitle if title has not been obtained from app store
@property (copy) NSString *title;

// Description to return from localizedDescription if the description has not been obtained from
// the app store
@property (copy) NSString *description;

// Can be used to prevent displaying of in app purchases in older versions of the app
// which do not support it yet
@property (copy) NSString *minimumVersion;

// An extra string to display in the store, such as "On sale 50% off for a limited time!"
@property (copy) NSString *extraInformation;

// Hint to the store view controller whether this item should show up in the list
@property BOOL isHidden;

// When set, will bypass the store and just process the purchase
@property BOOL isFree;

// Defaults to YES; Will be set to NO if iTunes returns that the product
// is invalid upon querying for it
@property  (readonly) BOOL isValid;

// Set to the name of a file to read using [UIImage imageNamed:] to associate
// with the product
@property (copy) NSString *productImageName;

// Returns an image based on the productImageName
// if productImageName is nil then will attempt to return a default image 
// based on the type of product with the following file names:
//   default-nonconsumable-image
//   default-consumable-image
//   default-autorenewable-image
//
// if productImageName file is not found will return nil
// (obviously including the default ones if there are no corresponding files)
@property (readonly) UIImage *productImage;

// The following properties are valid when the data has been retrieved from
// iTunes by the ASTStoreController; If there is no data, the methods
// will return nil or use the values provided for title/description above. 
// See SKProduct for more information
@property(nonatomic, readonly) NSString *localizedPrice;
@property(nonatomic, readonly) NSString *localizedDescription;
@property(nonatomic, readonly) NSString *localizedTitle;
@property(nonatomic, readonly) NSDecimalNumber *price;
@property(nonatomic, readonly) NSLocale *priceLocale;


@end
