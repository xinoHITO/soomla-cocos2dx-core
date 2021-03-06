/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#ifndef __CCRewardStorage_H_
#define __CCRewardStorage_H_

#include "cocos2d.h"
#include "CCReward.h"
#include "CCSequenceReward.h"

namespace soomla {
    class CCRewardStorage: public cocos2d::Ref {
    public:
        static CCRewardStorage *getInstance();

        virtual void setRewardStatus(CCReward *reward, bool give);
        virtual void setRewardStatus(CCReward *reward, bool give, bool notify);
        virtual bool isRewardGiven(CCReward *reward);
        virtual int getTimesGiven(CCReward *reward);
        virtual int getLastSeqIdxGiven(CCSequenceReward *sequenceReward);
        virtual void setLastSeqIdxGiven(CCSequenceReward *sequenceReward, unsigned int idx);
    private:
        void setTimesGiven(CCReward *reward, bool up, bool notify);
        const char* keyRewards(const char* rewardId, const char* postfix);
        const char* keyRewardIdxSeqGiven(const char* rewardId);
        const char* keyRewardTimesGiven(const char* rewardId);
        const char* keyRewardLastGiven(const char* rewardId);
    };
}

#endif //__CCRewardStorage_H_
