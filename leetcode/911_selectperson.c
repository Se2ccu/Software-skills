typedef struct {
    int *top;
    int *time;
    int size;
} TopVotedCandidate;


TopVotedCandidate* topVotedCandidateCreate(int* persons, int personsSize, int* times, int timesSize) {
    if (!persons || !times || personsSize == 0 || timesSize == 0) {
        return NULL;
    }
    
    TopVotedCandidate *obj = (TopVotedCandidate *)malloc(sizeof(TopVotedCandidate));
    if (!obj) {
        return NULL;
    }

    memset(obj, 0, sizeof(TopVotedCandidate));

    obj->top = (int *)malloc(sizeof(int) * timesSize);
    obj->time = (int *)malloc(sizeof(int) * timesSize);

    int *distrbute = (int *)malloc(sizeof(int) * timesSize);
    if (!distrbute) {
        return NULL;
    }
    memset(distrbute, 0, sizeof(int) * timesSize);

    obj->size = timesSize;

    int topId = -1;
    for (int i = 0; i < timesSize; i++) {
        distrbute[persons[i]]++;
        if (topId == -1 || distrbute[persons[i]] >= distrbute[topId]) {
            topId = persons[i];
        }
        obj->top[i] = topId;

        obj->time[i] = times[i];
    }

    free(distrbute);

    return obj;
}

int topVotedCandidateQ(TopVotedCandidate* obj, int t) {
    if (!obj || !obj->time || !obj->top) {
        return -1;
    }
    int left = 0;
    int right = obj->size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (obj->time[mid] <= t) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return obj->top[left - 1];

}

void topVotedCandidateFree(TopVotedCandidate* obj) {
    free(obj->time);
    free(obj->top);
    free(obj);
}

/**
 * Your TopVotedCandidate struct will be instantiated and called as such:
 * TopVotedCandidate* obj = topVotedCandidateCreate(persons, personsSize, times, timesSize);
 * int param_1 = topVotedCandidateQ(obj, t);
 
 * topVotedCandidateFree(obj);
*/