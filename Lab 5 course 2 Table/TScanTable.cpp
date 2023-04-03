#include "TScanTable.h"

PTDatValue TScanTable::FindRecord(TKey key)
{
    int i;
    SetRetCode(TAB_OK);
    for (i = 0; i < dataCount; i++) {
        if (pData[i]->GetKey() == key)
            break;
    }
    efficiency = i + 1;
    if (i < dataCount) {
        curPos = i;
        return pData[i]->GetValue();
    }
    SetRetCode(TAB_NO_RECORD);
    return nullptr;
}

bool TScanTable::InsertRecord(TKey key, PTDatValue value)
{
    if (IsFull()) {
        SetRetCode(TAB_FULL);
        return false;
    }
    pData[dataCount++] = new TTabRecord(key, value);
    SetRetCode(TAB_OK);
    return true;
}

void TScanTable::DeleteRecord(TKey key)
{
    PTDatValue t = FindRecord(key);
    if (t == nullptr)
        SetRetCode(TAB_NO_RECORD);
    else {
        SetRetCode(TAB_OK);
        pData[curPos] = pData[dataCount - 1];
        pData[--dataCount] = nullptr;
    }

}
