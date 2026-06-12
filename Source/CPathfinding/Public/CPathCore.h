// // Copyright Dominik Trautman. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include <vector>
#include "Containers/Queue.h"
#include "CPathfindingThread.h"
#include "CPathCore.generated.h"
class ACPathVolume;


// TODO: convert to world subsystem ?
UCLASS()
class CPATHFINDING_API ACPathCore : public AActor
{
	GENERATED_BODY()

	friend class FCPathfindingThread;
	
	
	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
protected:
	static ACPathCore* Instance;
	
	static bool bWasInstanceCreated;
	
	int32 ExpectedThreadCount;
	
	std::vector<FCPathfindingThread*> Threads;

	TQueue<std::pair<FCPathResult*, PathResultDelegate>, EQueueMode::Mpsc> OutputQueue;

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
public:
	ACPathCore();
	virtual ~ACPathCore() override;
	
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginDestroy() override;
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
public:
	static ACPathCore* GetInstance(UWorld* World);
	static bool DoesInstanceExist();
	static void EnableNewInstanceCreation();

public:
	// This is called by CPathVolumes before Octrees are deleted
	// BeginDestroy() is latent and may ba called AFTER Octree is deleted, causing a crash
	// so this is necessary
	void StopAndDeleteThreads();
	
	// Using this directly is unsafe, please use the FindPathAsync function in ACPathVolume class.
	void AssignAsyncRequest(const FCPathRequest& Request);
	
protected:
	static void PrintCoreMessage(FString Message);
	
	FCPathfindingThread* CreateThread(int32 ThreadIndex);
};







