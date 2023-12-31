#include "hidden_triples.h"
#include <stdlib.h>

int hidden_triples(SudokuBoard *p_board)
{
    int hidden_triples_cases = 0;
    HiddenTriple *triples = malloc(0);

    // row iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every row
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count = 0; // in that row, how many can be j?
            int index_1 = 0; // index of hidden single cell in the row
            int index_2 = 0;
            int index_3 = 0;
            int value_1 = 0; // index of hidden single cell in the row
            int value_2 = 0;
            int value_3 = 0;
            bool r_invalid = true;
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell in the row
            {
                if (p_board->p_rows[i][k]->num_candidates == 1) continue;
                if (p_board->p_rows[i][k]->candidates[j] == 1)
                {
                    candidate_count++;
                    if (index_1 && index_2)
                    {
                        index_3 = k;
                    }
                    else if (index_1)
                    {
                        index_2 = k;
                    }
                    else
                    {
                        index_1 = k;
                    }
                    value_1 = j + 1;
                }
            }
            if (candidate_count == 3) // only 1 cell can be j
            {
                for (int l = 0; l < BOARD_SIZE; l++)
                {
                    int candi = 0;
                    value_2 = l + 1;
                    if (p_board->p_rows[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_rows[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_rows[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (candi == 1)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_rows[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n + 1;
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 == 3)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_rows[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        r_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 2)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_rows[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2  && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n + 1;
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 2)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_rows[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2  && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        r_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 3)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_rows[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != 2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n + 1;
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_rows[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 1)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_rows[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        r_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!r_invalid) // only 1 cell can be j
            {
                HiddenTriple temp_triple;
                temp_triple.p_cells[0] = p_board->p_boxes[i][index_1];
                temp_triple.p_cells[1] = p_board->p_boxes[i][index_2];
                temp_triple.p_cells[2] = p_board->p_boxes[i][index_3];
                temp_triple.values[0] = value_1;
                temp_triple.values[1] = value_2;
                temp_triple.values[2] = value_3;
                int already_checked = 0;
                for (int l = 0; l < hidden_triples_cases; l++)
                    if ((triples[l].p_cells[0] == temp_triple.p_cells[0] && triples[l].p_cells[1] == temp_triple.p_cells[1] && triples[l].p_cells[2] == temp_triple.p_cells[2]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[1] && triples[l].p_cells[1] == temp_triple.p_cells[2] && triples[l].p_cells[2] == temp_triple.p_cells[0]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[2] && triples[l].p_cells[1] == temp_triple.p_cells[0] && triples[l].p_cells[2] == temp_triple.p_cells[1]))
                        already_checked = 1;
                if (!already_checked)
                {
                    hidden_triples_cases++;
                    triples = realloc(triples, hidden_triples_cases * sizeof(HiddenTriple));
                    triples[hidden_triples_cases - 1] = temp_triple;
                }
            }
        }
    }

    // column iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every column
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count = 0; // in that row, how many can be j?
            int index_1 = 0; // index of hidden single cell in the row
            int index_2 = 0;
            int index_3 = 0;
            int value_1 = 0; // index of hidden single cell in the row
            int value_2 = 0;
            int value_3 = 0;
            bool c_invalid = true;
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell in the row
            {
                if (p_board->p_cols[i][k]->num_candidates == 1) continue;
                if (p_board->p_cols[i][k]->candidates[j] == 1)
                {
                    candidate_count++;
                    if (index_1 && index_2)
                    {
                        index_3 = k;
                    }
                    else if (index_1)
                    {
                        index_2 = k;
                    }
                    else
                    {
                        index_1 = k;
                    }
                    value_1 = j + 1;
                }
            }
            if (candidate_count == 3) // only 1 cell can be j
            {
                for (int l = 0; l < BOARD_SIZE; l++)
                {
                    int candi = 0;
                    value_2 = l;
                    if (p_board->p_cols[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_cols[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_cols[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (candi == 1)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_cols[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 == 3)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_cols[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        c_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 2)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_cols[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 2)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_cols[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        c_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 3)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_cols[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != 2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_cols[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 1)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_cols[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        c_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!c_invalid) // only 1 cell can be j
            {
                HiddenTriple temp_triple;
                temp_triple.p_cells[0] = p_board->p_boxes[i][index_1];
                temp_triple.p_cells[1] = p_board->p_boxes[i][index_2];
                temp_triple.p_cells[2] = p_board->p_boxes[i][index_3];
                temp_triple.values[0] = value_1;
                temp_triple.values[1] = value_2;
                temp_triple.values[2] = value_3;
                int already_checked = 0;
                for (int l = 0; l < hidden_triples_cases; l++)
                    if ((triples[l].p_cells[0] == temp_triple.p_cells[0] && triples[l].p_cells[1] == temp_triple.p_cells[1] && triples[l].p_cells[2] == temp_triple.p_cells[2]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[1] && triples[l].p_cells[1] == temp_triple.p_cells[2] && triples[l].p_cells[2] == temp_triple.p_cells[0]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[2] && triples[l].p_cells[1] == temp_triple.p_cells[0] && triples[l].p_cells[2] == temp_triple.p_cells[1]))
                        already_checked = 1;
                if (!already_checked)
                {
                    hidden_triples_cases++;
                    triples = realloc(triples, hidden_triples_cases * sizeof(HiddenTriple));
                    triples[hidden_triples_cases - 1] = temp_triple;
                }
            }
        }
    }

    // box iteration
    for (int i = 0; i < BOARD_SIZE; i++) // iterate over every box
    {
        for (int j = 0; j < BOARD_SIZE; j++) // iterate over every number 1-9
        {
            int candidate_count = 0; // in that row, how many can be j?
            int index_1 = 0; // index of hidden single cell in the row
            int index_2 = 0;
            int index_3 = 0;
            int value_1 = 0; // index of hidden single cell in the row
            int value_2 = 0;
            int value_3 = 0;
            bool b_invalid = true;
            for (int k = 0; k < BOARD_SIZE; k++) // iterate over every cell in the row
            {
                if (p_board->p_boxes[i][k]->num_candidates == 1) continue;
                if (p_board->p_boxes[i][k]->candidates[j] == 1)
                {
                    candidate_count++;
                    if (index_1 && index_2)
                    {
                        index_3 = k;
                    }
                    else if (index_1)
                    {
                        index_2 = k;
                    }
                    else
                    {
                        index_1 = k;
                    }
                    value_1 = j + 1;
                }
            }
            if (candidate_count == 3) // only 1 cell can be j
            {
                for (int l = 0; l < BOARD_SIZE; l++)
                {
                    int candi = 0;
                    value_2 = l;
                    if (p_board->p_boxes[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_boxes[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (p_board->p_boxes[i][index_1]->candidates[l] == 1 && l != value_1 - 1)
                    {
                        candi++;
                    }
                    if (candi == 1)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_boxes[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 == 3)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_boxes[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        b_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 2)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_boxes[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 2)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_boxes[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        b_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                    if (candi == 3)
                    {
                        int avail = 0;
                        for (int m = 0; m < BOARD_SIZE; m++)
                        {
                            if ((p_board->p_boxes[i][m]->candidates[value_2 - 1] == 1) && (m != index_1 && m != index_2 && m != index_3))
                            {
                                avail++;
                            }
                        }
                        if (avail == 0)
                        {
                            int candi_1 = 0;
                            for (int n = 0; n < BOARD_SIZE; n++)
                            {
                                value_3 = n;
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (p_board->p_boxes[i][index_1]->candidates[n] == 1 && l != value_1 - 1 && l != value_2 - 1)
                                {
                                    candi_1++;
                                }
                                if (candi_1 >= 1)
                                {
                                    int avail_1 = 0;
                                    for (int o = 0; o < BOARD_SIZE; o++)
                                    {
                                        if ((p_board->p_boxes[i][o]->candidates[value_3 - 1] == 1) && (o != index_1 && o != index_2 && o != index_3))
                                        {
                                            avail_1++;
                                        }
                                    }
                                    if (avail_1 == 0)
                                    {
                                        b_invalid = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!b_invalid) // only 1 cell can be j
            {
                HiddenTriple temp_triple;
                temp_triple.p_cells[0] = p_board->p_boxes[i][index_1];
                temp_triple.p_cells[1] = p_board->p_boxes[i][index_2];
                temp_triple.p_cells[2] = p_board->p_boxes[i][index_3];
                temp_triple.values[0] = value_1;
                temp_triple.values[1] = value_2;
                temp_triple.values[2] = value_3;
                int already_checked = 0;
                for (int l = 0; l < hidden_triples_cases; l++)
                    if ((triples[l].p_cells[0] == temp_triple.p_cells[0] && triples[l].p_cells[1] == temp_triple.p_cells[1] && triples[l].p_cells[2] == temp_triple.p_cells[2]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[1] && triples[l].p_cells[1] == temp_triple.p_cells[2] && triples[l].p_cells[2] == temp_triple.p_cells[0]) ||
                        (triples[l].p_cells[0] == temp_triple.p_cells[2] && triples[l].p_cells[1] == temp_triple.p_cells[0] && triples[l].p_cells[2] == temp_triple.p_cells[1]))
                        already_checked = 1;
                if (!already_checked)
                {
                    hidden_triples_cases++;
                    triples = realloc(triples, hidden_triples_cases * sizeof(HiddenTriple));
                    triples[hidden_triples_cases - 1] = temp_triple;
                }
            }
        }
    }

    //int *candidates = malloc(4);
    int *candidates = malloc(3 * sizeof(int));
    for (int i = 0; i < hidden_triples_cases; i++)
    {
        // Make sure to allocate enough memory for the candidates array
        ///int *candidates = malloc(3 * sizeof(int));

        candidates[0] = triples[i].values[0];
        candidates[1] = triples[i].values[1];
        candidates[2] = triples[i].values[2];
        
        // Call set_candidates on each cell in the pair with both candidates
        set_candidates(triples[i].p_cells[0], candidates, 3);
        set_candidates(triples[i].p_cells[1], candidates, 3);
        set_candidates(triples[i].p_cells[2], candidates, 3);

        // Free the memory allocated for candidates
        //free(candidates);
    }
    free(triples);
    free(candidates);
    return hidden_triples_cases; // returns total cells solved by hidden triples
}
