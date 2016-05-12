//
//  CoreDataBaseTestCase.m
//  ContentfulSDK
//
//  Created by Boris Bügling on 28/04/14.
//
//

#import "CoreDataBaseTestCase.h"
#import "CoreDataManager.h"
#import "SyncInfo.h"

@implementation CoreDataBaseTestCase

-(void)buildPersistenceManagerWithDefaultClient:(BOOL)defaultClient {
    [super buildPersistenceManagerWithDefaultClient:defaultClient];

    self.persistenceManager.classForAssets = [Asset class];
    self.persistenceManager.classForSpaces = [SyncInfo class];

    NSArray* contentTypeIds = @[ @"1nGOrvlRTaMcyyq4IEa8ea", @"6bAvxqodl6s4MoKuWYkmqe",
                                 @"6PnRGY1dxSUmaQ2Yq2Ege2", @"cat", @"test" ];

    Class c = [ManagedCat class];
    for (NSString* contentTypeId in contentTypeIds) {
        [self.persistenceManager setClass:c forEntriesOfContentTypeWithIdentifier:contentTypeId];
    }
}

-(CDAPersistenceManager*)createPersistenceManagerWithClient:(CDAClient*)client {
    if (self.query) {
        return [[CoreDataManager alloc] initWithClient:client
                                         dataModelName:@"CoreDataExample"
                                                 query:self.query];
    }

    return [[CoreDataManager alloc] initWithClient:client dataModelName:@"CoreDataExample"];
}

-(void)deleteStore {
    CoreDataManager* manager = (CoreDataManager*)self.persistenceManager;
    [[NSFileManager defaultManager] removeItemAtURL:manager.storeURL error:nil];
}

-(void)setUp {
    [super setUp];

    [self deleteStore];
}

-(void)tearDown {
    [super tearDown];

    [self deleteStore];
}

@end
