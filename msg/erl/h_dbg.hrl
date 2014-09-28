-define(H_DEBUG_MSG(Msg, Args),
    io:format(Msg ++ ", Module: ~w, Fun: ~w" ++ ", Line: ~w, Node: ~w", Args ++ [element(1, element(2, process_info(self(), current_function))), element(2, element(2, process_info(self(), current_function))), ?LINE, node()])).
